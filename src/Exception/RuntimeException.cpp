#ifndef __NEUTRONTL_EXCEPTION_RUNTIMEEXCEPTION_CPP__
#define __NEUTRONTL_EXCEPTION_RUNTIMEEXCEPTION_CPP__

#include "RuntimeException.hpp"

namespace ntl
{
    RuntimeException::RuntimeException(
        const String &why,
        const String &where)
        : Exception(
              NTL_STRING("runtime exception"),
              why,
              where) {}

} // namespace ntl

#endif
