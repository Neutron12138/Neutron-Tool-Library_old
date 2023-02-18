#ifndef __NEUTRONTL_EXCEPTION_EXCEPTION_CPP__
#define __NEUTRONTL_EXCEPTION_EXCEPTION_CPP__

#include <iostream>
#include "Exception.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    Exception::Exception(
        const std::exception &exception)
        : m_what(NTL_STRING("exception")),
          m_why(exception.what()) {}

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
           << NTL_STRING("what:") << m_what << std::endl
           << NTL_STRING("why:") << m_why << std::endl
           << NTL_STRING("where:") << m_where << std::endl;
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