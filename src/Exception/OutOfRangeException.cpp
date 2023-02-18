#ifndef __NEUTRONTL_EXCEPTION_OUTOFRANGEEXCEPTION_CPP__
#define __NEUTRONTL_EXCEPTION_OUTOFRANGEEXCEPTION_CPP__

#include "OutOfRangeException.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    OutOfRangeException::OutOfRangeException(
        const std::out_of_range &exception)
        : Exception(
              NTL_STRING("out of range"),
              exception.what(),
              NTL_STRING("")) {}

    OutOfRangeException::OutOfRangeException(
        const String &why,
        const String &where)
        : Exception(
              NTL_STRING("out of range"),
              why,
              where) {}

} // namespace ntl

#endif