#ifndef __NEUTRONTL_EXCEPTION_OUTOFRANGEEXCEPTION_CPP__
#define __NEUTRONTL_EXCEPTION_OUTOFRANGEEXCEPTION_CPP__

#include "OutOfRangeException.hpp"

namespace ntl
{
    OutOfRangeException::OutOfRangeException(const std::wstring &why, const std::wstring &where) : Exception(L"out of range", why, where) {}

} // namespace ntl

#endif