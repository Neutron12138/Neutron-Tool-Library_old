#ifndef __NEUTRONTL_BASE_OBJECT_CPP__
#define __NEUTRONTL_BASE_OBJECT_CPP__

#include "Object.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    String
    Object::as_string() const
    {
        return StringUtils::to_string(NTL_CSTRING("Object,"), this);
    }
} // namespace ntl

#endif