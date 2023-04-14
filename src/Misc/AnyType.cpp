#ifndef __NEUTRONTL_MISC_ANYTYPE_CPP__
#define __NEUTRONTL_MISC_ANYTYPE_CPP__

#include "AnyType.hpp"

namespace ntl
{
    template <typename TargetType>
    AnyType::operator TargetType() const
    {
        return TargetType();
    }

    template <typename TargetType, typename... ArgsType>
    TargetType AnyType::as(
        ArgsType &&...args)
    {
        return TargetType(std::forward<ArgsType>(args)...);
    }

} // namespace ntl

#endif
