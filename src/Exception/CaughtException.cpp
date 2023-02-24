#ifndef __NEUTRONTL_EXCEPTION_CAUGHTEXCEPTION_CPP__
#define __NEUTRONTL_EXCEPTION_CAUGHTEXCEPTION_CPP__

#include "CaughtException.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    CaughtException::CaughtException(
        const Exception &exception,
        const String &where)
        : Exception(
              NTL_STRING("caught exception"),
              NTL_STRING("An exception was caught at runtime"),
              where),
          m_caught_exception(exception)
    {
        m_where_array.push_back(where);
    }

    CaughtException::CaughtException(
        const CaughtException &exception,
        const String &where)
        : Exception(
              NTL_STRING("caught exception"),
              NTL_STRING("An exception was caught at runtime"),
              where),
          m_caught_exception(exception.get_caught_exception()),
          m_where_array(exception.get_where_array())
    {
        m_where_array.push_back(where);
    }

    const std::vector<String> &
    CaughtException::get_where_array() const
    {
        return m_where_array;
    }

    const Exception &
    CaughtException::get_caught_exception() const
    {
        return m_caught_exception;
    }

    void
    CaughtException::print_self(
        OutputStream &os) const
    {
        for (auto iter = m_where_array.crbegin(); iter != m_where_array.crend(); iter++)
        {
            os << NTL_STRING("Exception caught at:") << *iter << std::endl;
        }
        os << m_caught_exception;
    }

} // namespace ntl

#endif