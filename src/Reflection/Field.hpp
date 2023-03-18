#ifndef __NEUTRONTL_REFLECTION_FIELD_HPP__
#define __NEUTRONTL_REFLECTION_FIELD_HPP__

#include <optional>
#include "Member.hpp"
#include "FieldSign.hpp"

namespace ntl
{
    /// @brief 属性
    template <typename m_FieldPointer>
    class NTL_ALIGN Field : public Member<m_FieldPointer>
    {
    public:
        /// @brief 属性指针
        using FieldPointer = m_FieldPointer;

        using SelfType = Field;
        using ParentType = Member<m_FieldPointer>;

    protected:
        /// @brief 属性的签名
        std::optional<FieldSign> m_sign;

    public:
        Field() = default;
        template <typename FieldType>
        explicit Field(FieldType pointer);
        template <typename FieldType>
        explicit Field(FieldType pointer, const FieldSign &sign);
        explicit Field(const SelfType &from) = default;
        ~Field() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        /// @brief 获取属性签名
        /// @return 属性签名
        const std::optional<FieldSign> &get_sign() const;
    };

} // namespace ntl

#endif