#ifndef __NEUTRONTL_BASE_OBJECT_CPP__
#define __NEUTRONTL_BASE_OBJECT_CPP__

#include "Object.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    std::wstring Object::as_string() const
    {
        return WStringUtils::to_string("Object,", this);
    }
} // namespace ntl

#endif