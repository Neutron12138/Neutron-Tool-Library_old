#ifndef __NEUTRONTL_REFLECTION_FIELD_CPP__
#define __NEUTRONTL_REFLECTION_FIELD_CPP__

#include "Field.hpp"
#include "../Exception/NullPointerException.hpp"

namespace ntl
{
    template <typename m_FieldPointer>
    template <typename FieldType>
    Field<m_FieldPointer>::Field(
        FieldType pointer)
        : Field<m_FieldPointer>::ParentType(pointer) {}

    template <typename m_FieldPointer>
    template <typename FieldType>
    Field<m_FieldPointer>::Field(
        FieldType pointer,
        const FieldSign &sign)
        : Field<m_FieldPointer>::ParentType(pointer),
          m_sign(sign) {}

    template <typename m_FieldPointer>
    const std::optional<FieldSign> &
    Field<m_FieldPointer>::get_sign() const
    {
        return m_sign;
    }

} // namespace ntl

#endif