#ifndef __NEUTRONTL_BASE_BASICOBJECT_CPP__
#define __NEUTRONTL_BASE_BASICOBJECT_CPP__

#include "BasicObject.hpp"
#include "../String/StringUtils.hpp"
#include "../Serialization/Serialization.hpp"
#include "../Serialization/Deserializer.hpp"

namespace ntl
{
    Serialization
    serialize(
        const BasicObject &object)
    {
        return Serialization(
            StringUtils::to_string(
                NTL_STRING("ntl::BasicObject at "),
                &object));
    }

    template <>
    BasicObject
    deserialize(
        const Serialization &serialization)
    {
        return BasicObject();
    }

} // namespace ntl

#endif
