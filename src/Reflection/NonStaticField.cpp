#ifndef __NEUTRONTL_REFLECTION_NONSTATICFIELD_CPP__
#define __NEUTRONTL_REFLECTION_NONSTATICFIELD_CPP__

#include "NonStaticField.hpp"
#include "../Exception/NullPointerException.hpp"

namespace ntl
{
    template <typename FieldType>
    NonStaticField::NonStaticField(FieldType pointer)
        : NonStaticField::ParentType(pointer) {}

    template <typename ReturnType>
    ReturnType &
    NonStaticField::of(
        void *object) const
    {
        if (m_pointer == nullptr || object == nullptr)
            throw NullPointerException(
                NTL_STRING("template <typename ReturnType> ReturnType &NonStaticField::of(Reflectible &object) const"));

        using FieldType = ReturnType(Reflectible::*);
        return reinterpret_cast<Reflectible *>(object)->*reinterpret_cast<FieldType>(m_pointer);
    }

} // namespace ntl

#endif