#ifndef __NEUTRONTL_REFLECTION_FIELD_CPP__
#define __NEUTRONTL_REFLECTION_FIELD_CPP__

#include "Field.hpp"
#include "../Exception/NullPointerException.hpp"

namespace ntl
{
    template <typename FieldType>
    Field::Field(FieldType pointer)
        : m_pointer(reinterpret_cast<Field::FieldPointer>(pointer)) {}

    typename Field::FieldPointer
    Field::get_pointer() const
    {
        return m_pointer;
    }

    template <typename ReturnType>
    ReturnType &
    Field::of(
        Reflectible &object) const
    {
        if (m_pointer == nullptr)
            throw NullPointerException(
                NTL_STRING("template <typename ReturnType> ReturnType &Field::of(Reflectible &object) const"));

        using FieldType = ReturnType(Reflectible::*);
        return object.*reinterpret_cast<FieldType>(m_pointer);
    }

} // namespace ntl

#endif