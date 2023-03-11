#ifndef __NEUTRONTL_REFLECTION_STATICFIELD_CPP__
#define __NEUTRONTL_REFLECTION_STATICFIELD_CPP__

#include "StaticField.hpp"
#include "../Exception/NullPointerException.hpp"

namespace ntl
{
    template <typename FieldType>
    StaticField::StaticField(FieldType pointer)
        : StaticField::ParentType(pointer) {}

    template <typename ReturnType>
    ReturnType &
    StaticField::of() const
    {
        if (m_pointer == nullptr)
            throw NullPointerException(
                NTL_STRING("template <typename ReturnType> ReturnType &StaticField::of() const"));

        using FieldType = ReturnType(*);
        return *reinterpret_cast<FieldType>(m_pointer);
    }

} // namespace ntl

#endif