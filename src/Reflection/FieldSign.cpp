#ifndef __NEUTRONTL_REFLECTION_FIELDSIGN_CPP__
#define __NEUTRONTL_REFLECTION_FIELDSIGN_CPP__

#include "FieldSign.hpp"

namespace ntl
{
    FieldSign::FieldSign(
        const Type &field_type)
        : m_field_type(field_type) {}

    const Type &
    FieldSign::get_field_type() const
    {
        return m_field_type;
    }

    template <typename T>
    bool
    FieldSign::check() const
    {
        return m_field_type == get_type<T>();
    }

} // namespace ntl

#endif