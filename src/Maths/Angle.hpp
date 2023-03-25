#ifndef __NEUTRONTL_MATHS_ANGLE_HPP__
#define __NEUTRONTL_MATHS_ANGLE_HPP__

#include "../Base/BasicObject.hpp"
#include "../Base/Type.hpp"

namespace ntl
{
    /// @brief 角度
    /// @tparam m_ValueType 值类型
    template <typename m_ValueType>
    class NTL_ALIGN Angle : public BasicObject
    {
    public:
        /// @brief 值类型
        using ValueType = m_ValueType;

        using SelfType = Angle<ValueType>;
        using ParentType = BasicObject;

        /// @brief 角度单位
        enum AngleUnit
        {
            /// @brief 没有单位
            None = 0,

            /// @brief 弧度
            Radian,

            /// @brief 角度
            Degree,

            /// @brief 总数
            Count
        };

    public:
        /// @brief 角度单位
        AngleUnit unit;

        /// @brief 值
        ValueType value;

    public:
        Angle() = default;
        explicit Angle(float v, AngleUnit u = AngleUnit::Radian);
        explicit Angle(const SelfType &from) = default;
        ~Angle() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

        bool operator==(const SelfType &another) const;
        bool operator!=(const SelfType &another) const;

        SelfType operator+(const SelfType &another) const;
        SelfType operator-(const SelfType &another) const;

        SelfType operator*(const ValueType &another) const;
        SelfType operator/(const ValueType &another) const;

        SelfType &operator+=(const SelfType &another);
        SelfType &operator-=(const SelfType &another);

        SelfType &operator*=(const ValueType &another);
        SelfType &operator/=(const ValueType &another);

        operator ValueType() const;

    public:
        /// @brief 转换为弧度
        /// @return 弧度
        ValueType as_radian() const;

        /// @brief 转换为角度
        /// @return 角度
        ValueType as_degree() const;

        /// @brief 转换为相同的角度单位
        SelfType as_same_unit(const SelfType &another) const;

    public:
        /// @brief 转换为弧度
        /// @param value 值
        /// @return 弧度
        static ValueType as_radian(const ValueType &value);

        /// @brief 转换为角度
        /// @param value 值
        /// @return 角度
        static ValueType as_degree(const ValueType &value);
    };

    template <typename ValueType>
    OutputStream &operator<<(OutputStream &os, const Angle<ValueType> &angle);

} // namespace ntl

#endif