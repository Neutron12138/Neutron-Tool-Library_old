#ifndef __NEUTRONTL_REFLECTION_NONSTATICFIELD_CPP__
#define __NEUTRONTL_REFLECTION_NONSTATICFIELD_CPP__

#include "NonStaticField.hpp"
#include "../Exception/NullPointerException.hpp"

namespace ntl
{
    template <typename FieldType>
    NonStaticField::NonStaticField(
        FieldType pointer)
        : NonStaticField::ParentType(pointer) {}

    template <typename FieldType>
    NonStaticField::NonStaticField(
        FieldType pointer,
        const FieldSign &sign)
        : NonStaticField::ParentType(pointer, sign) {}

    template <typename ReturnType>
    ReturnType &
    NonStaticField::of(
        void *object) const
    {
        if (m_pointer == nullptr || object == nullptr)
            throw NullPointerException(
                NTL_MAKE_STATEMENT_INFO("template <typename ReturnType> ReturnType &NonStaticField::of(BasicObject &object) const"));

        using FieldType = ReturnType(BasicObject::*);

        if (m_sign.has_value())
            if (!m_sign->check<ReturnType>())
                throw TypeErrorException(
                    StringUtils::to_string(
                        NTL_STRING("The type of the field is \""),
                        m_sign->get_field_type().get_info().name(),
                        NTL_STRING("\", but the return type is \""),
                        get_type<ReturnType>().get_info().name(),
                        NTL_STRING("\"")),
                    NTL_MAKE_STATEMENT_INFO("template <typename ReturnType> ReturnType &NonStaticField::of(BasicObject &object) const"));

        return reinterpret_cast<BasicObject *>(object)->*reinterpret_cast<FieldType>(m_pointer);
    }

} // namespace ntl

#endif