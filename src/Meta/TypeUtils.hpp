#ifndef __NEUTRONTL_META_TYPEUTILS_HPP__
#define __NEUTRONTL_META_TYPEUTILS_HPP__

#include <vector>
#include "../Base/Object.hpp"
#include "TypeInfo.hpp"

namespace ntl
{
    /// @brief 类型工具
    class TypeUtils : public Object
    {
    public:
        using SelfType = TypeUtils;
        using ParentType = Object;

    public:
        constexpr TypeUtils() noexcept = default;
        constexpr explicit TypeUtils(const SelfType &from) noexcept = default;
        ~TypeUtils() override = default;

    public:
        constexpr SelfType &operator=(const SelfType &from) = default;

    public:
        /// @brief 检查类型是否符合规则
        /// @tparam Type 类型
        /// @param fundamental_type 基础类型
        /// @return 是否符合规则
        template <typename Type>
        static bool is_fit(typename FundamentalTypeInfo<Type>::FundamentalType fundamental_type);

        /// @brief 检查类型是否符合规则
        /// @tparam Type 类型
        /// @param compound_type 复合类型
        /// @return 是否符合规则
        template <typename Type>
        static bool is_fit(typename CompoundTypeInfo<Type>::CompoundType compound_type);

        /// @brief 检查类型是否符合规则
        /// @tparam Type 类型
        /// @param type_attribute 类型属性
        /// @return 是否符合规则
        template <typename Type>
        static bool is_fit(typename TypeAttributeInfo<Type>::TypeAttribute type_attribute);

        /// @brief 检查类型是否符合规则
        /// @tparam Type 类型
        /// @param supported_operations 支持的操作
        /// @return 是否符合规则
        template <typename Type>
        static bool is_fit(typename SupportedOperationsInfo<Type>::SupportedOperations supported_operations);
    };
} // namespace ntl

#endif