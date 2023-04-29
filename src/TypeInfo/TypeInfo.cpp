#ifndef __NEUTRONTL_TYPEINFO_TYPEINFO_CPP__
#define __NEUTRONTL_TYPEINFO_TYPEINFO_CPP__

#include "TypeInfo.hpp"

namespace ntl
{
    template <typename m_ClassType>
    Type
    TypeInfo<m_ClassType>::get_type()
    {
        return ntl::get_type<ClassType>();
    }

    template <typename ClassType>
    TypeInfo<ClassType>
    get_type_info(
        const ClassType &)
    {
        return TypeInfo<ClassType>();
    }

    template <typename ClassType>
    TypeInfo<ClassType>
    get_type_info()
    {
        return TypeInfo<ClassType>();
    }

} // namespace ntl

#endif
