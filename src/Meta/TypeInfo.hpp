#ifndef __NEUTRONTL_META_TYPEINFO_HPP__
#define __NEUTRONTL_META_TYPEINFO_HPP__

#include <type_traits>
#include <typeinfo>
#include "../Base/Object.hpp"
#include "TypeInfoEnum.hpp"

#define TYPEINFO(type) static constexpr bool is_##type = std::is_##type<Type>::value;

namespace ntl
{
    template <typename m_Type>
    class TypeInfo : public Object
    {
    public:
        using Type = m_Type;

        using SelfType = TypeInfo<Type>;
        using ParentType = Object;

    public:
        /// @brief 类型名称
        static constexpr char *type_name = ""; // typeid(Type).name();

        //
        // 基础类型
        //

        /// @brief 是否为void类型
        static constexpr bool is_void = std::is_void_v<Type>;

        /// @brief 是否为空指针类型
        static constexpr bool is_null_pointer = std::is_null_pointer_v<Type>;

        /// @brief 是否为整数类型
        static constexpr bool is_integral = std::is_integral_v<Type>;

        /// @brief 是否为浮点数类型
        static constexpr bool is_floating_point = std::is_floating_point_v<Type>;

        /// @brief 是否为数组类型
        static constexpr bool is_array = std::is_array_v<Type>;

        /// @brief 是否为枚举类型
        static constexpr bool is_enum = std::is_enum_v<Type>;

        /// @brief 是否为联合体类型
        static constexpr bool is_union = std::is_union_v<Type>;

        /// @brief 是否为非联合体类型
        static constexpr bool is_class = std::is_class_v<Type>;

        /// @brief 是否为函数类型
        static constexpr bool is_function = std::is_function_v<Type>;

        /// @brief 是否为指针类型
        static constexpr bool is_pointer = std::is_pointer_v<Type>;

        /// @brief 是否为左值引用类型
        static constexpr bool is_lvalue_reference = std::is_lvalue_reference_v<Type>;

        /// @brief 是否为右值引用类型
        static constexpr bool is_rvalue_reference = std::is_rvalue_reference_v<Type>;

        /// @brief 是否为非静态成员对象类型
        static constexpr bool is_member_object_pointer = std::is_member_object_pointer_v<Type>;

        /// @brief 是否为非静态成员函数类型
        static constexpr bool is_member_function_pointer = std::is_member_function_pointer_v<Type>;

        //
        // 复合类型
        //

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