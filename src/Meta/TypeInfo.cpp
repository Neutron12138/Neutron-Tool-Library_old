#ifndef __NEUTRONTL_META_TYPEINFO_CPP__
#define __NEUTRONTL_META_TYPEINFO_CPP__

#include "TypeInfo.hpp"

namespace ntl
{
    template <typename Type>
    TypeInfo<Type>
    get_type_info(
        const Type &)
    {
        return TypeInfo<Type>();
    }

    template <typename Type>
    TypeInfo<Type>
    get_type_info()
    {
        return TypeInfo<Type>();
    }
} // namespace ntl

#endif