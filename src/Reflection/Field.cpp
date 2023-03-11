#ifndef __NEUTRONTL_REFLECTION_FIELD_CPP__
#define __NEUTRONTL_REFLECTION_FIELD_CPP__

#include "Field.hpp"
#include "../Exception/NullPointerException.hpp"

namespace ntl
{
    template <typename m_FieldPointer>
    template <typename FieldType>
    Field<m_FieldPointer>::Field(FieldType pointer)
        : m_pointer(
              reinterpret_cast<
                  Field<m_FieldPointer>::FieldPointer>(
                  pointer)) {}

} // namespace ntl

#endif