#ifndef __NEUTRONTL_MISC_ENUMERATION_HPP__
#define __NEUTRONTL_MISC_ENUMERATION_HPP__

#include "../Base/BasicObject.hpp"
#include "../Base/Type.hpp"

namespace ntl
{
    /// @brief 枚举
    /// @tparam m_ValueType 值类型
    template <typename m_ValueType>
    class BasicEnumeration : public BasicObject
    {
    public:
        using ValueType = m_ValueType;

        using SelfType = BasicEnumeration<ValueType>;
        using ParentType = BasicObject;

    protected:
        /// @brief 值
        ValueType m_value;

    public:
        BasicEnumeration(const ValueType &value);
        explicit BasicEnumeration(const SelfType &from) = default;
        ~BasicEnumeration() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
        bool operator==(const SelfType &another) const;
        bool operator!=(const SelfType &another) const;
        operator ValueType() const;

    public:
        /// @brief 获取值
        /// @return 值
        const ValueType &get_value() const;
    };

    /// @brief 枚举
    using Enumeration = BasicEnumeration<UInt64>;

} // namespace ntl

#endif