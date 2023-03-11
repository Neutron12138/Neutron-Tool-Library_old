#ifndef __NEUTRONTL_REFLECTION_FIELD_HPP__
#define __NEUTRONTL_REFLECTION_FIELD_HPP__

#include "../Base/BasicObject.hpp"

namespace ntl
{
    class Reflectible;

    /// @brief 属性
    template <typename m_FieldPointer>
    class NTL_ALIGN Field : public BasicObject
    {
    public:
        /// @brief 属性指针
        using FieldPointer = m_FieldPointer;

        using SelfType = Field;
        using ParentType = BasicObject;

    protected:
        /// @brief 属性
        FieldPointer m_pointer = nullptr;

    public:
        Field() = default;
        template <typename FieldType>
        explicit Field(FieldType pointer);
        explicit Field(const SelfType &from) = default;
        ~Field() = default;
    };

} // namespace ntl

#endif