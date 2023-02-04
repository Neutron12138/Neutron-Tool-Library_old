#ifndef __NEUTRONTL_EXCEPTION_EXCEPTION_CPP__
#define __NEUTRONTL_EXCEPTION_EXCEPTION_CPP__

#include <iostream>
#include "Exception.hpp"

namespace ntl
{
    Exception::Exception(
        const String &what,
        const String &why,
        const String &where)
        : m_what(what), m_why(why), m_where(where) {}

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

    std::wostream &
    operator<<(
        std::wostream &os,
        const Exception &exception)
    {
        os << L"Exception:" << std::endl
           << L"what:" << exception.what() << std::endl
           << L"why:" << exception.why() << std::endl
           << L"where:" << exception.where() << std::endl;
        return os;
    }
} // namespace ntl

#endif