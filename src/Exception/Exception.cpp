#ifndef __NEUTRONTL_EXCEPTION_EXCEPTION_CPP__
#define __NEUTRONTL_EXCEPTION_EXCEPTION_CPP__

#include <iostream>
#include "Exception.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    Exception::Exception(
        const std::exception &exception,
        const String &where)
        : m_what(NTL_STRING("exception")),
          m_why(exception.what()),
          m_where(where) {}

    Exception::Exception(
        const String &what,
        const String &why,
        const String &where)
        : m_what(what),
          m_why(why),
          m_where(where) {}

    inline const String &
    Exception::what() const
    {
        return m_what;
    }

    inline const String &
    Exception::why() const
    {
        return m_why;
    }

    inline const String &
    Exception::where() const
    {
        return m_where;
    }

    void
    Exception::print_self(
        OutputStream &os) const
    {
        os << NTL_STRING("Exception:") << std::endl
           << serialize().get_serialization() << std::endl;
    }

    Serialization
    Exception::serialize()
    {
        return Serialization(
            StringUtils::to_string(
                NTL_STRING("what:"), m_what, "\n",
                NTL_STRING("why:"), m_why, "\n",
                NTL_STRING("where:"), m_where));
    }

    Serialization
    Exception::serialize() const
    {
        return Serialization(
            StringUtils::to_string(
                NTL_STRING("what:"), m_what, "\n",
                NTL_STRING("why:"), m_why, "\n",
                NTL_STRING("where:"), m_where));
    }

    Exception::SelfType &
    Exception::deserialize(
        const Serialization &serialization)
    {
        // 按行分割
        std::vector<ntl::String> result =
            StringUtils::split_by_line(serialization.get_serialization());

        // 检查行数
        if (result.size() != 3)
            throw Exception(
                NTL_STRING("invalid argument"),
                StringUtils::to_string(
                    NTL_STRING("Three lines are required, but there are "),
                    result.size(),
                    NTL_STRING(" lines")),
                NTL_STRING("Exception::SelfType &Exception::deserialize(const Serialization &serialization)"));

        // 匹配结果
        ntl::Match m;

        // 匹配"what"段
        if (!StringUtils::search(result.at(0), m, ntl::Regex(NTL_STRING("what:(.*)"))))
            throw Exception(
                NTL_STRING("invalid argument"),
                NTL_STRING("\"what\" segment error"),
                NTL_STRING("Exception::SelfType &Exception::deserialize(const Serialization &serialization)"));
        m_what = m.str(1);

        // 匹配"why"段
        if (!StringUtils::search(result.at(1), m, ntl::Regex(NTL_STRING("why:(.*)"))))
            throw Exception(
                NTL_STRING("invalid argument"),
                NTL_STRING("\"why\" segment error"),
                NTL_STRING("Exception::SelfType &Exception::deserialize(const Serialization &serialization)"));
        m_why = m.str(1);

        // 匹配"where"段
        if (!StringUtils::search(result.at(2), m, ntl::Regex(NTL_STRING("where:(.*)"))))
            throw Exception(
                NTL_STRING("invalid argument"),
                NTL_STRING("\"where\" segment error"),
                NTL_STRING("Exception::SelfType &Exception::deserialize(const Serialization &serialization)"));
        m_where = m.str(1);

        return *this;
    }

    OutputStream &
    operator<<(
        OutputStream &os,
        const Exception &exception)
    {
        exception.print_self(os);
        return os;
    }
} // namespace ntl

#endif