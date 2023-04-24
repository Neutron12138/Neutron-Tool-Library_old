#ifndef __NEUTRONTL_EXCEPTION_INVALIDARGUMENTEXCEPTION_CPP__
#define __NEUTRONTL_EXCEPTION_INVALIDARGUMENTEXCEPTION_CPP__

#include "InvalidArgumentException.hpp"

namespace ntl
{
    InvalidArgumentException::InvalidArgumentException(
        const String &why,
        const String &where)
        : Exception(
              NTL_STRING("invalid argument"),
              why,
              where) {}

} // namespace ntl

#endif
