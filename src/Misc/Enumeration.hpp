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

        bool operator>(const SelfType &another) const;
        bool operator>=(const SelfType &another) const;
        bool operator<(const SelfType &another) const;
        bool operator<=(const SelfType &another) const;

        SelfType operator|(const SelfType &another) const;
        SelfType operator&(const SelfType &another) const;

        SelfType &operator|=(const SelfType &another);
        SelfType &operator&=(const SelfType &another);

        operator ValueType() const;
        operator bool() const;

    public:
        /// @brief 获取值
        /// @return 值
        const ValueType &get_value() const;

        /// @brief 值是否为0
        /// @return 值是否为0
        bool is_zero() const;
    };

    /// @brief 枚举
    using Enumeration = BasicEnumeration<Int64>;

    //
    // 模板特化
    //

    /// @brief 字符串枚举
    template <>
    class BasicEnumeration<String> : public BasicObject
    {
    public:
        using ValueType = String;

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

    /// @brief 字符串枚举
    using StringEnumeration = BasicEnumeration<String>;

    //
    // 重载函数
    //

    template <typename ValueType>
    OutputStream &operator<<(OutputStream &os, const BasicEnumeration<ValueType> &enumeration);

} // namespace ntl

#endif