#ifndef __NEUTRONTL_EXCEPTION_TYPEERROREXCEPTION_CPP__
#define __NEUTRONTL_EXCEPTION_TYPEERROREXCEPTION_CPP__

#include "TypeErrorException.hpp"

namespace ntl
{
    TypeErrorException::TypeErrorException(
        const String &why,
        const String &where)
        : Exception(
              NTL_STRING("type error"),
              why,
              where) {}

} // namespace ntl

#endif