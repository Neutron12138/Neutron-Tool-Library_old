#ifndef __NEUTRONTL_META_SUPPORTEDOPERATIONSINFO_HPP__
#define __NEUTRONTL_META_SUPPORTEDOPERATIONSINFO_HPP__

#include <type_traits>
#include "../../Base/Object.hpp"

namespace ntl
{
    /// @brief 支持的操作信息
    /// @tparam m_Type 类型
    template <typename m_Type>
    class SupportedOperationsInfo : public Object
    {
    public:
        using Type = m_Type;

        using SelfType = SupportedOperationsInfo<Type>;
        using ParentType = Object;

        /// @brief 支持的操作
        enum SupportedOperations
        {
            /// @brief 未知，不可能出现此结果
            Unknown = 0,

            /// @brief 带有针对特定实参的构造函数
            Constructible = 0x1 << 0,

            /// @brief 带有针对特定实参的平凡的构造函数
            TriviallyConstructible = 0x1 << 1,

            /// @brief 带有针对特定实参的不抛出异常的构造函数
            NothrowConstructible = 0x1 << 2,

            /// @brief 有默认构造函数
            DefaultConstructible = 0x1 << 3,

            /// @brief 有平凡的默认构造函数
            TriviallyDefaultConstructible = 0x1 << 4,

            /// @brief 有不抛出异常的默认构造函数
            NothrowDefaultConstructible = 0x1 << 5,

            /// @brief 拥有复制构造函数
            CopyConstructible = 0x1 << 6,

            /// @brief 拥有平凡的复制构造函数
            TriviallyCopyConstructible = 0x1 << 7,

            /// @brief 拥有不抛出异常的复制构造函数
            NothrowCopyConstructible = 0x1 << 8,

            /// @brief 拥有移动构造函数
            MoveConstructible = 0x1 << 9,

            /// @brief 拥有平凡的移动构造函数
            TriviallyMoveConstructible = 0x1 << 10,

            /// @brief 拥有不抛出异常的移动构造函数
            NothrowMoveConstructible = 0x1 << 11,

            /// @brief 拥有复制赋值运算符
            CopyAssignable = 0x1 << 12,

            /// @brief 拥有平凡的复制赋值运算符
            TriviallyCopyAssignable = 0x1 << 13,

            /// @brief 拥有不抛出异常的复制赋值运算符
            NothrowCopyAssignable = 0x1 << 14,

            /// @brief 拥有移动赋值运算符
            MoveAssignable = 0x1 << 15,

            /// @brief 拥有平凡的移动赋值运算符
            TriviallyMoveAssignable = 0x1 << 16,

            /// @brief 拥有不抛出异常的移动赋值运算符
            NothrowMoveAssignable = 0x1 << 17,

            /// @brief 拥有未被弃置的析构函数
            Destructible = 0x1 << 18,

            /// @brief 拥有未被弃置的平凡的析构函数
            TriviallyDestructible = 0x1 << 19,

            /// @brief 拥有未被弃置的不抛出异常的析构函数
            NothrowDestructible = 0x1 << 20,

            /// @brief 拥有虚析构函数
            HasVirtualDestructor = 0x1 << 21,

            /// @brief 能与同类型的对象交换
            Swappable = 0x1 << 22,

            /// @brief 能与同类型的对象不抛出异常地交换
            NothrowSwappable = 0x1 << 23,

            /// @brief 总数
            Count = 24,
        };

    public:
        /// @brief 是否带有针对特定实参的构造函数
        static constexpr bool is_constructible = std::is_constructible_v<Type>;

        /// @brief 是否带有针对特定实参的平凡的构造函数
        static constexpr bool is_trivially_constructible = std::is_trivially_constructible_v<Type>;

        /// @brief 是否带有针对特定实参的不抛出异常的构造函数
        static constexpr bool is_nothrow_constructible = std::is_nothrow_constructible_v<Type>;

        /// @brief /// @brief 是否有默认构造函数
        static constexpr bool is_default_constructible = std::is_default_constructible_v<Type>;

        /// @brief 是否有平凡的默认构造函数
        static constexpr bool is_trivially_default_constructible = std::is_trivially_default_constructible_v<Type>;

        /// @brief 是否有不抛出异常的默认构造函数
        static constexpr bool is_nothrow_default_constructible = std::is_nothrow_default_constructible_v<Type>;

        /// @brief 是否拥有复制构造函数
        static constexpr bool is_copy_constructible = std::is_copy_constructible_v<Type>;

        /// @brief 是否拥有平凡的复制构造函数
        static constexpr bool is_trivially_copy_constructible = std::is_trivially_copy_constructible_v<Type>;

        /// @brief 是否拥有不抛出异常的复制构造函数
        static constexpr bool is_nothrow_copy_constructible = std::is_nothrow_copy_constructible_v<Type>;

        /// @brief 是否拥有移动构造函数
        static constexpr bool is_move_constructible = std::is_move_constructible_v<Type>;

        /// @brief 是否拥有平凡的移动构造函数
        static constexpr bool is_trivially_move_constructible = std::is_trivially_move_constructible_v<Type>;

        /// @brief 是否拥有不抛出异常的移动构造函数
        static constexpr bool is_nothrow_move_constructible = std::is_nothrow_move_constructible_v<Type>;

        /// @brief 是否拥有复制赋值运算符
        static constexpr bool is_copy_assignable = std::is_copy_assignable_v<Type>;

        /// @brief 是否拥有平凡的复制赋值运算符
        static constexpr bool is_trivially_copy_assignable = std::is_trivially_copy_assignable_v<Type>;

        /// @brief 是否拥有不抛出异常的复制赋值运算符
        static constexpr bool is_nothrow_copy_assignable = std::is_nothrow_copy_assignable_v<Type>;

        /// @brief 是否拥有移动赋值运算符
        static constexpr bool is_move_assignable = std::is_move_assignable_v<Type>;

        /// @brief 是否拥有平凡的移动赋值运算符
        static constexpr bool is_trivially_move_assignable = std::is_trivially_move_assignable_v<Type>;

        /// @brief 是否拥有不抛出异常的移动赋值运算符
        static constexpr bool is_nothrow_move_assignable = std::is_nothrow_move_assignable_v<Type>;

        /// @brief 是否拥有未被弃置的析构函数
        static constexpr bool is_destructible = std::is_destructible_v<Type>;

        /// @brief 是否拥有未被弃置的平凡的析构函数
        static constexpr bool is_trivially_destructible = std::is_trivially_destructible_v<Type>;

        /// @brief 是否拥有未被弃置的不抛出异常的析构函数
        static constexpr bool is_nothrow_destructible = std::is_nothrow_destructible_v<Type>;

        /// @brief 是否拥有虚析构函数
        static constexpr bool has_virtual_destructor = std::has_virtual_destructor_v<Type>;

        /// @brief 是否能与同类型的对象交换
        static constexpr bool is_swappable = std::is_swappable_v<Type>;

        /// @brief 是否能与同类型的对象不抛出异常地交换
        static constexpr bool is_nothrow_swappable = std::is_nothrow_swappable_v<Type>;

        /// @brief 支持的操作
        static constexpr SupportedOperations supported_operations =
            static_cast<SupportedOperations>(
                (is_constructible ? SupportedOperations::Constructible : SupportedOperations::Unknown) |
                (is_trivially_constructible ? SupportedOperations::TriviallyConstructible : SupportedOperations::Unknown) |
                (is_nothrow_constructible ? SupportedOperations::NothrowConstructible : SupportedOperations::Unknown) |
                (is_default_constructible ? SupportedOperations::DefaultConstructible : SupportedOperations::Unknown) |
                (is_trivially_default_constructible ? SupportedOperations::TriviallyDefaultConstructible : SupportedOperations::Unknown) |
                (is_nothrow_default_constructible ? SupportedOperations::NothrowDefaultConstructible : SupportedOperations::Unknown) |
                (is_copy_constructible ? SupportedOperations::CopyConstructible : SupportedOperations::Unknown) |
                (is_trivially_copy_constructible ? SupportedOperations::TriviallyCopyConstructible : SupportedOperations::Unknown) |
                (is_nothrow_copy_constructible ? SupportedOperations::NothrowCopyConstructible : SupportedOperations::Unknown) |
                (is_move_constructible ? SupportedOperations::MoveConstructible : SupportedOperations::Unknown) |
                (is_trivially_move_constructible ? SupportedOperations::TriviallyMoveConstructible : SupportedOperations::Unknown) |
                (is_nothrow_move_constructible ? SupportedOperations::NothrowMoveConstructible : SupportedOperations::Unknown) |
                (is_copy_assignable ? SupportedOperations::CopyAssignable : SupportedOperations::Unknown) |
                (is_trivially_copy_assignable ? SupportedOperations::TriviallyCopyAssignable : SupportedOperations::Unknown) |
                (is_nothrow_copy_assignable ? SupportedOperations::NothrowCopyAssignable : SupportedOperations::Unknown) |
                (is_move_assignable ? SupportedOperations::MoveAssignable : SupportedOperations::Unknown) |
                (is_trivially_move_assignable ? SupportedOperations::TriviallyMoveAssignable : SupportedOperations::Unknown) |
                (is_nothrow_move_assignable ? SupportedOperations::NothrowMoveAssignable : SupportedOperations::Unknown) |
                (is_destructible ? SupportedOperations::Destructible : SupportedOperations::Unknown) |
                (is_trivially_destructible ? SupportedOperations::TriviallyDestructible : SupportedOperations::Unknown) |
                (is_nothrow_destructible ? SupportedOperations::NothrowDestructible : SupportedOperations::Unknown) |
                (has_virtual_destructor ? SupportedOperations::HasVirtualDestructor : SupportedOperations::Unknown) |
                (is_swappable ? SupportedOperations::Swappable : SupportedOperations::Unknown) |
                (is_nothrow_swappable ? SupportedOperations::NothrowSwappable : SupportedOperations::Unknown));

    public:
        constexpr SupportedOperationsInfo() = default;
        constexpr explicit SupportedOperationsInfo(const SelfType &from) = default;
        ~SupportedOperationsInfo() override = default;

    public:
        constexpr SelfType &operator=(const SelfType &from) = default;
    };
} // namespace ntl

#endif