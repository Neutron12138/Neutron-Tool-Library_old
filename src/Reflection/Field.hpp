#ifndef __NEUTRONTL_REFLECTION_FIELD_HPP__
#define __NEUTRONTL_REFLECTION_FIELD_HPP__

#include "../Base/BasicObject.hpp"

namespace ntl
{
    class Reflectible;

    /// @brief 属性
    class Field : public BasicObject
    {
    public:
        using SelfType = Field;
        using ParentType = BasicObject;

        /// @brief 属性指针
        using FieldPointer = void *(Reflectible::*);

    protected:
        /// @brief 属性
        FieldPointer m_pointer = nullptr;

    public:
        Field() = default;
        template <typename FieldType>
        explicit Field(FieldType pointer);
        explicit Field(const SelfType &from) = default;
        ~Field() = default;

    public:
        FieldPointer get_pointer() const;

    public:
        template <typename ReturnType>
        ReturnType &of(Reflectible &object) const;
    };

} // namespace ntl

#endif