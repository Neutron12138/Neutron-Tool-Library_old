#ifndef __NEUTRONTL_TYPEINFO_TYPEUTILS_CPP__
#define __NEUTRONTL_TYPEINFO_TYPEUTILS_CPP__

#include "TypeUtils.hpp"

namespace ntl
{
    template <typename Type>
    bool
    TypeUtils::is_fit(
        typename FundamentalTypeInfo<Type>::FundamentalType fundamental_type)
    {
        return FundamentalTypeInfo<Type>::fundamental_type == fundamental_type;
    }

    template <typename Type>
    bool
    TypeUtils::is_fit(
        typename CompoundTypeInfo<Type>::CompoundType compound_type)
    {
        return CompoundTypeInfo<Type>::compound_type == compound_type;
    }

    template <typename Type>
    bool
    TypeUtils::is_fit(
        typename TypeAttributeInfo<Type>::TypeAttribute type_attribute)
    {
        return TypeAttributeInfo<Type>::type_attribute == type_attribute;
    }

    template <typename Type>
    bool
    TypeUtils::is_fit(
        typename SupportedOperationsInfo<Type>::SupportedOperations supported_operations)
    {
        return SupportedOperationsInfo<Type>::supported_operations == supported_operations;
    }
} // namespace ntl

#endif