#ifndef __NEUTRONTL_TYPEINFO_TYPEATTRIBUTEINFO_HPP__
#define __NEUTRONTL_TYPEINFO_TYPEATTRIBUTEINFO_HPP__

#include <type_traits>
#include "../Base/Object.hpp"

namespace ntl
{
    /// @brief 类型属性信息
    /// @tparam m_ClassType 信息
    template <typename m_ClassType>
    class TypeAttributeInfo : public Object
    {
    public:
        using ClassType = m_ClassType;

        using SelfType = TypeAttributeInfo<ClassType>;
        using ParentType = Object;

        /// @brief 类型属性
        enum ClassTypeAttribute : long
        {
            /// @brief 未知，不可能会出现此结果
            Unknown = 0,

            /// @brief const限定类型
            Const = 0x1 << 0,

            /// @brief volatile限定类型
            Volatile = 0x1 << 1,

            /// @brief 平凡类型
            Trivial = 0x1 << 2,

            /// @brief 可平凡复制类型
            TriviallyCopyable = 0x1 << 3,

            /// @brief 标准对象类型
            StandardLayout = 0x1 << 4,

            /// @brief 类型对象的每一位都对其值有贡献
            HasUniqueObjectRepresentations = 0x1 << 5,

            /// @brief 拥有强结构相等性，C++20
            // HasStrongStructuralEquality = 0x1 << 6,

            /// @brief 类型为类（但非联合体）类型且无非静态数据成员
            Empty = 0x1 << 7,

            /// @brief 多态类类型
            Polymorphic = 0x1 << 8,

            /// @brief 抽象类类型
            Abstract = 0x1 << 9,

            /// @brief final类类型
            Final = 0x1 << 10,

            /// @brief 聚合类型
            Aggregate = 0x1 << 11,

            /// @brief 有符号算术类型
            Signed = 0x1 << 12,

            /// @brief 无符号算术类型
            Unsigned = 0x1 << 13,

            /// @brief 有已知边界的数组类型，C++20
            // BoundedArray = 0x1 << 14,

            /// @brief 无已知边界的数组类型，C++20
            // UnboundedArray = 0x1 << 15,

            /// @brief 有作用域枚举类型，C++23
            // ScopedEnum = 0x1 << 16,

            /// @brief 总计
            Count = 13,
        };

    public:
        /// @brief 是否有const限定符
        static constexpr bool is_const = std::is_const_v<ClassType>;

        /// @brief 是否有volatile限定符
        static constexpr bool is_volatile = std::is_volatile_v<ClassType>;

        /// @brief 是否为平凡类型
        static constexpr bool is_trivial = std::is_trivial_v<ClassType>;

        /// @brief 是否可平凡复制
        static constexpr bool is_trivially_copyable = std::is_trivially_copyable_v<ClassType>;

        /// @brief 是否为标准布局
        static constexpr bool is_standard_layout = std::is_standard_layout_v<ClassType>;

        /// @brief 是否该类型对象的每一位都对其值有贡献
        static constexpr bool has_unique_object_representations = std::has_unique_object_representations_v<ClassType>;

        /// @brief 是否拥有强结构相等性，C++20
        // static constexpr bool has_strong_structural_equality = std::has_strong_structural_equality_v<ClassType>;

        /// @brief 是否为类（但非联合体）类型且无非静态数据成员
        static constexpr bool is_empty = std::is_empty_v<ClassType>;

        /// @brief 是否为多态类类型
        static constexpr bool is_polymorphic = std::is_polymorphic_v<ClassType>;

        /// @brief 是否为抽象类类型
        static constexpr bool is_abstract = std::is_abstract_v<ClassType>;

        /// @brief 是否为 final 类类型
        static constexpr bool is_final = std::is_final_v<ClassType>;

        /// @brief 是否为聚合类型
        static constexpr bool is_aggregate = std::is_aggregate_v<ClassType>;

        /// @brief 是否为有符号算术类型
        static constexpr bool is_signed = std::is_signed_v<ClassType>;

        /// @brief 是否为无符号算术类型
        static constexpr bool is_unsigned = std::is_unsigned_v<ClassType>;

        /// @brief 是否为有已知边界的数组类型，C++20
        // static constexpr bool is_bounded_array = std::is_bounded_array_v<ClassType>;

        /// @brief 是否为无已知边界的数组类型，C++20
        // static constexpr bool is_unbounded_array = std::is_unbounded_array_v<ClassType>;

        /// @brief 是否为有作用域枚举类型，C++23
        // static constexpr bool is_scoped_enum = std::is_scoped_enum_v<ClassType>;

        /// @brief 类型属性
        static constexpr ClassTypeAttribute type_attribute =
            static_cast<ClassTypeAttribute>(
                (is_const ? ClassTypeAttribute::Const : ClassTypeAttribute::Unknown) |
                (is_volatile ? ClassTypeAttribute::Volatile : ClassTypeAttribute::Unknown) |
                (is_trivial ? ClassTypeAttribute::Trivial : ClassTypeAttribute::Unknown) |
                (is_trivially_copyable ? ClassTypeAttribute::TriviallyCopyable : ClassTypeAttribute::Unknown) |
                (is_standard_layout ? ClassTypeAttribute::StandardLayout : ClassTypeAttribute::Unknown) |
                (has_unique_object_representations ? ClassTypeAttribute::HasUniqueObjectRepresentations : ClassTypeAttribute::Unknown) |
                (is_empty ? ClassTypeAttribute::Empty : ClassTypeAttribute::Unknown) |
                (is_polymorphic ? ClassTypeAttribute::Polymorphic : ClassTypeAttribute::Unknown) |
                (is_abstract ? ClassTypeAttribute::Abstract : ClassTypeAttribute::Unknown) |
                (is_final ? ClassTypeAttribute::Final : ClassTypeAttribute::Unknown) |
                (is_aggregate ? ClassTypeAttribute::Aggregate : ClassTypeAttribute::Unknown) |
                (is_signed ? ClassTypeAttribute::Signed : ClassTypeAttribute::Unknown) |
                (is_unsigned ? ClassTypeAttribute::Unsigned : ClassTypeAttribute::Unknown));

    public:
        constexpr TypeAttributeInfo() = default;
        constexpr TypeAttributeInfo(const SelfType &from) = default;
        ~TypeAttributeInfo() override = default;

    public:
        constexpr SelfType &operator=(const SelfType &from) = default;
    };
} // namespace ntl

#endif