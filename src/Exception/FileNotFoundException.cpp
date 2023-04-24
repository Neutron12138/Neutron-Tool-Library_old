#ifndef __NEUTRONTL_EXCEPTION_FILENOTFOUNDEXCEPTION_CPP__
#define __NEUTRONTL_EXCEPTION_FILENOTFOUNDEXCEPTION_CPP__

#include "FileNotFoundException.hpp"

namespace ntl
{
    FileNotFoundException::FileNotFoundException(
        const String &why,
        const String &where)
        : Exception(
              NTL_STRING("file not found"),
              why,
              where) {}

} // namespace ntl

#endif
