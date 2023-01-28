#ifndef __NEUTRONTL_EXCEPTION_EXCEPTION_CPP__
#define __NEUTRONTL_EXCEPTION_EXCEPTION_CPP__

#include <iostream>
#include "Exception.hpp"

namespace ntl
{
    Exception::Exception(const std::wstring &what, const std::wstring &why, const std::wstring &where) : m_what(what), m_why(why), m_where(where) {}

    const std::wstring &Exception::what() const
    {
        return m_what;
    }

    const std::wstring &Exception::why() const
    {
        return m_why;
    }

    const std::wstring &Exception::where() const
    {
        return m_where;
    }

    std::wostream &operator<<(std::wostream &os, const Exception &exception)
    {
        os << L"Exception:" << std::endl
           << L"what:" << exception.what() << std::endl
           << L"why:" << exception.why() << std::endl
           << L"where:" << exception.where() << std::endl;
        return os;
    }
} // namespace ntl

#endif