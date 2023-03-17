#ifndef __NEUTRONTL_REFLECTION_NONSTATICFIELD_HPP__
#define __NEUTRONTL_REFLECTION_NONSTATICFIELD_HPP__

#include "Field.hpp"

namespace ntl
{
    /// @brief 非静态属性
    class NTL_ALIGN NonStaticField : public Field<void *(BasicObject::*)>
    {
    public:
        using FieldPointer = void *(BasicObject::*);

        using SelfType = NonStaticField;
        using ParentType = Field<FieldPointer>;

    public:
        NonStaticField() = default;
        template <typename FieldType>
        explicit NonStaticField(FieldType pointer);
        explicit NonStaticField(const SelfType &from) = default;
        ~NonStaticField() = default;

    public:
        template <typename ReturnType>
        ReturnType &of(void *object) const;
    };

} // namespace ntl

#endif