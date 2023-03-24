#ifndef __NEUTRONTL_TYPEINFO_TYPEINFO_HPP__
#define __NEUTRONTL_TYPEINFO_TYPEINFO_HPP__

#include <type_traits>
#include <typeinfo>
#include "FundamentalTypeInfo.hpp"
#include "CompoundTypeInfo.hpp"
#include "TypeAttributeInfo.hpp"
#include "AttributeQueryInfo.hpp"
#include "SupportedOperationsInfo.hpp"

namespace ntl
{
    /// @brief 类型信息
    /// @tparam m_Type 类型
    template <typename m_Type>
    class TypeInfo
        : virtual public FundamentalTypeInfo<m_Type>,
          virtual public CompoundTypeInfo<m_Type>,
          virtual public TypeAttributeInfo<m_Type>,
          virtual public SupportedOperationsInfo<m_Type>,
          virtual public AttributeQueryInfo<m_Type>
    {
    public:
        /// @brief 类型
        using Type = m_Type;

        using SelfType = TypeInfo<Type>;
        using ParentType = Object;

    public:
        constexpr TypeInfo() = default;
        constexpr explicit TypeInfo(const SelfType &from) = default;
        ~TypeInfo() override = default;

    public:
        constexpr SelfType &operator=(const SelfType &from) = default;
    };

    /// @brief 获取类型信息
    /// @tparam Type 类型
    /// @return 类型信息
    template <typename Type>
    TypeInfo<Type> get_type_info(const Type &);

    /// @brief 获取类型信息
    /// @tparam Type 类型
    /// @return 类型信息
    template <typename Type>
    TypeInfo<Type> get_type_info();

} // namespace ntl

#endif