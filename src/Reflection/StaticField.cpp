#ifndef __NEUTRONTL_REFLECTION_STATICFIELD_CPP__
#define __NEUTRONTL_REFLECTION_STATICFIELD_CPP__

#include "StaticField.hpp"
#include "../Exception/NullPointerException.hpp"
#include "../Exception/TypeErrorException.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    template <typename FieldType>
    StaticField::StaticField(
        FieldType pointer)
        : StaticField::ParentType(pointer) {}

    template <typename FieldType>
    StaticField::StaticField(
        FieldType pointer,
        const FieldSign &sign)
        : StaticField::ParentType(pointer, sign) {}

    template <typename ReturnType>
    ReturnType &
    StaticField::of() const
    {
        if (m_pointer == nullptr)
            throw NullPointerException(
                NTL_STRING("template <typename ReturnType> ReturnType &StaticField::of() const"));

        using FieldType = ReturnType(*);

        if (m_sign.has_value())
            if (!m_sign->check<ReturnType>())
                throw TypeErrorException(
                    StringUtils::to_string(
                        NTL_STRING("The type of the field is \""),
                        m_sign->get_field_type().get_info().name(),
                        NTL_STRING("\", but the return type is \""),
                        get_type<ReturnType>().get_info().name(),
                        NTL_STRING("\"")),
                    NTL_STRING("template <typename ReturnType> ReturnType &StaticField::of() const"));

        return *reinterpret_cast<FieldType>(m_pointer);
    }

} // namespace ntl

#endif