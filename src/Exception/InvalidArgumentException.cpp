#ifndef __NEUTRONTL_EXCEPTION_INVALIDARGUMENTEXCEPTION_CPP__
#define __NEUTRONTL_EXCEPTION_INVALIDARGUMENTEXCEPTION_CPP__

#include "InvalidArgumentException.hpp"

namespace ntl
{
    InvalidArgumentException::InvalidArgumentException(const std::wstring &why, const std::wstring &where) : Exception(L"invalid argument", why, where) {}

} // namespace ntl

#endif