#ifndef __NEUTRONTL_EXCEPTION_NULLPOINTEREXCEPTION_CPP__
#define __NEUTRONTL_EXCEPTION_NULLPOINTEREXCEPTION_CPP__

#include "NullPointerException.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    NullPointerException::NullPointerException(
        const String &where)
        : Exception(NTL_CSTRING("null pointer"),
                    NTL_CSTRING("You tried to access a null pointer"),
                    where) {}
} // namespace ntl

#endif