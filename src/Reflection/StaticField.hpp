#ifndef __NEUTRONTL_REFLECTION_STATICFIELD_HPP__
#define __NEUTRONTL_REFLECTION_STATICFIELD_HPP__

#include "Field.hpp"

namespace ntl
{
    /// @brief 静态属性
    class NTL_ALIGN StaticField : public Field<void *(*)>
    {
    public:
        using FieldPointer = void *(*);

        using SelfType = StaticField;
        using ParentType = Field<FieldPointer>;

    public:
        StaticField() = default;
        template <typename FieldType>
        StaticField(FieldType pointer);
        template <typename FieldType>
        StaticField(FieldType pointer, const FieldSign &sign);
        StaticField(const SelfType &from) = default;
        ~StaticField() = default;

    public:
        template <typename ReturnType>
        ReturnType &of() const;
    };

} // namespace ntl

#endif