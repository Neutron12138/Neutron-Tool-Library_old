#ifndef __NEUTRONTL_EXCEPTION_FILEEXCEPTION_CPP__
#define __NEUTRONTL_EXCEPTION_FILEEXCEPTION_CPP__

#include "FileException.hpp"

namespace ntl
{
    FileException::FileException(
        const String &why,
        const String &where)
        : Exception(
              NTL_STRING("file exception"),
              why,
              where) {}

} // namespace ntl

#endif
