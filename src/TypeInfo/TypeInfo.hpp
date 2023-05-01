#ifndef __NEUTRONTL_TYPEINFO_TYPEINFO_HPP__
#define __NEUTRONTL_TYPEINFO_TYPEINFO_HPP__

#include <type_traits>
#include <typeinfo>
#include "FundamentalTypeInfo.hpp"
#include "CompoundTypeInfo.hpp"
#include "TypeAttributeInfo.hpp"
#include "AttributeQueryInfo.hpp"
#include "SupportedOperationsInfo.hpp"
#include "Type.hpp"

namespace ntl
{
    /// @brief 类型信息
    /// @tparam m_ClassType 类型
    template <typename m_ClassType>
    class TypeInfo
        : virtual public FundamentalTypeInfo<m_ClassType>,
          virtual public CompoundTypeInfo<m_ClassType>,
          virtual public TypeAttributeInfo<m_ClassType>,
          virtual public SupportedOperationsInfo<m_ClassType>,
          virtual public AttributeQueryInfo<m_ClassType>
    {
    public:
        /// @brief 类型
        using ClassType = m_ClassType;

        using SelfType = TypeInfo<ClassType>;
        using ParentType = Object;

    public:
        TypeInfo() = default;
        TypeInfo(const SelfType &from) = default;
        ~TypeInfo() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        static Type get_type();
    };

    /// @brief 获取类型信息
    /// @tparam ClassType 类型
    /// @return 类型信息
    template <typename ClassType>
    TypeInfo<ClassType> get_type_info(const ClassType &);

    /// @brief 获取类型信息
    /// @tparam ClassType 类型
    /// @return 类型信息
    template <typename ClassType>
    TypeInfo<ClassType> get_type_info();

} // namespace ntl

#endif