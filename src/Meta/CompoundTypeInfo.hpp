#ifndef __NEUTRONTL_META_COMPOUNDTYPEINFO_HPP__
#define __NEUTRONTL_META_COMPOUNDTYPEINFO_HPP__

#include <type_traits>
#include "../Base/Object.hpp"

namespace ntl
{
    /// @brief 复合类型信息
    /// @tparam m_Type 类型
    template <typename m_Type>
    class CompoundTypeInfo : public Object
    {
    public:
        using Type = m_Type;

        using SelfType = CompoundTypeInfo<Type>;
        using ParentType = Object;

        /// @brief 复合类型
        enum CompoundType
        {
            /// @brief 未知，不可能出现此结果
            Unknown = 0,

            /// @brief 基础类型
            Fundamental = 0x1 << 0,

            /// @brief 算术类型
            Arithmetic = 0x1 << 1,

            /// @brief 标量类型
            Scalar = 0x1 << 2,

            /// @brief 对象类型
            Object = 0x1 << 3,

            /// @brief 复合类型
            Compound = 0x1 << 4,

            /// @brief 引用类型
            Reference = 0x1 << 5,

            /// @brief 指向非静态成员函数或对象的指针类型
            MemberPointer = 0x1 << 6,

            /// @brief 总数
            CTCount = 7,
        };

    public:
        /// @brief 是否否为基础类型
        static constexpr bool is_fundamental = std::is_fundamental_v<Type>;

        /// @brief 是否否为算术类型
        static constexpr bool is_arithmetic = std::is_arithmetic_v<Type>;

        /// @brief 是否否为标量类型
        static constexpr bool is_scalar = std::is_scalar_v<Type>;

        /// @brief 是否否为对象类型
        static constexpr bool is_object = std::is_object_v<Type>;

        /// @brief 是否否为符合类型
        static constexpr bool is_compound = std::is_compound_v<Type>;

        /// @brief 是否否为引用类型
        static constexpr bool is_reference = std::is_reference_v<Type>;

        /// @brief 是否否为指向非静态成员函数或对象的指针类型
        static constexpr bool is_member_pointer = std::is_member_pointer_v<Type>;

        /// @brief 复合类型
        static constexpr CompoundType compound_type =
            static_cast<CompoundType>(
                (is_fundamental ? CompoundType::Fundamental : CompoundType::Unknown) |
                (is_arithmetic ? CompoundType::Arithmetic : CompoundType::Unknown) |
                (is_scalar ? CompoundType::Scalar : CompoundType::Unknown) |
                (is_object ? CompoundType::Object : CompoundType::Unknown) |
                (is_compound ? CompoundType::Compound : CompoundType::Unknown) |
                (is_reference ? CompoundType::Reference : CompoundType::Unknown) |
                (is_member_pointer ? CompoundType::MemberPointer : CompoundType::Unknown));

    public:
        constexpr CompoundTypeInfo() = default;
        constexpr explicit CompoundTypeInfo(const SelfType &from) = default;
        virtual ~CompoundTypeInfo() override = default;

    public:
        constexpr SelfType &operator=(const SelfType &from) = default;
    };
} // namespace ntl

#endif