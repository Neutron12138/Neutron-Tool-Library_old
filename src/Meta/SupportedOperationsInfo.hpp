#ifndef __NEUTRONTL_META_SUPPORTEDOPERATIONSINFO_HPP__
#define __NEUTRONTL_META_SUPPORTEDOPERATIONSINFO_HPP__

#include <type_traits>
#include "../Base/Object.hpp"

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
            Constructible,

            /// @brief 带有针对特定实参的平凡构造函数
            TriviallyConstructible,

            /// @brief 带有针对特定实参的不抛出异常地构造函数
            NothrowConstructible,

            /// @brief 有默认构造函数
            DefaultConstructible,

            /// @brief 有平凡的默认构造函数
            TriviallyDefaultConstructible,

            /// @brief 有不抛出异常地默认构造函数
            NothrowDefaultConstructible,

            /// @brief 拥有复制构造函数
            CopyConstructible,

            /// @brief 拥有平凡的复制构造函数
            TriviallyCopyConstructible,

            /// @brief 拥有不抛出异常地复制构造函数
            NothrowCopyConstructible,

            /// @brief 拥有移动构造函数
            MoveConstructible,

            /// @brief 拥有平凡的移动构造函数
            TriviallyMoveConstructible,

            /// @brief 拥有不抛出异常地移动构造函数
            NothrowMoveConstructible,

            /// @brief 拥有针对特定实参的赋值运算符
            Assignable,

            /// @brief 拥有针对特定实参的平凡的赋值运算符
            TriviallyAssignable,

            /// @brief 拥有针对特定实参的不抛出异常地赋值运算符
            NothrowAssignable,

            /// @brief 拥有复制赋值运算符
            CopyAssignable,

            /// @brief 拥有平凡的复制赋值运算符
            TriviallyCopyAssignable,

            /// @brief 拥有不抛出异常地复制赋值运算符
            NothrowCopyAssignable,

            /// @brief 拥有移动赋值运算符
            MoveAssignable,

            /// @brief 拥有平凡的移动赋值运算符
            TriviallyMoveAssignable,

            /// @brief 拥有不抛出异常地移动赋值运算符
            NothrowMoveAssignable,

            /// @brief 拥有未被弃置的析构函数
            Destructible,

            /// @brief 拥有未被弃置的平凡的析构函数
            TriviallyDestructible,

            /// @brief 拥有未被弃置的不抛出异常地析构函数
            NothrowDestructible,

            /// @brief 拥有虚析构函数
            HasVirtualDestructor,

            /// @brief 能与同类型的对象交换
            Swappable,

            /// @brief 能与同类型的对象不抛出异常地交换
            NothrowSwappable,

            /// @brief 总数
            Count,
        };

    public:
        constexpr SupportedOperationsInfo() = default;
        constexpr explicit SupportedOperationsInfo(const SelfType &from) = default;
        ~SupportedOperationsInfo() override = default;

    public:
        constexpr SelfType &operator=(const SelfType &from) = default;
    };
} // namespace ntl

#endif