#ifndef __NEUTRONTL_EXCEPTION_NULLPOINTEREXCEPTION_CPP__
#define __NEUTRONTL_EXCEPTION_NULLPOINTEREXCEPTION_CPP__

#include "NullPointerException.hpp"

namespace ntl
{
    NullPointerException::NullPointerException(const std::wstring &where) : Exception(L"null pointer", L"You tried to access a null pointer", where) {}
} // namespace ntl

#endif