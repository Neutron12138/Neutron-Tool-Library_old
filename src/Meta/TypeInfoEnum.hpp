#ifndef __NEUTRONTL_META_TYPEINFOENUM_HPP__
#define __NEUTRONTL_META_TYPEINFOENUM_HPP__

#include <type_traits>

namespace ntl
{
    /// @brief 类型信息枚举
    namespace TypeInfoEnum
    {
        /// @brief 基础类型
        enum FundamentalType
        {
            /// @brief void类型
            Void = 0,

            /// @brief 空指针类型
            NullPointer,

            /// @brief 整数类型
            Integral,

            /// @brief 浮点数类型
            FloatingPoint,

            /// @brief 数组类型
            Array,

            /// @brief 枚举类型
            Enum,

            /// @brief 联合体类型
            Union,

            /// @brief 非联合体类型
            Class,

            /// @brief 函数类型
            Function,

            /// @brief 指针类型
            Pointer,

            /// @brief 左值引用类型
            LValueReference,

            /// @brief 右值引用类型
            RValueReference,

            /// @brief 非静态成员对象类型
            MemberObjectPointer,

            /// @brief 非静态成员函数类型
            MemberFunctionPointer,

            /// @brief 总数
            BTCount,
        };

        /// @brief 复合类型
        enum CompoundType
        {
            /// @brief 基础类型
            Fundamental = 0,

            /// @brief 算术类型
            Arithmetic,

            /// @brief 标量类型
            Scalar,

            /// @brief 对象类型
            Object,

            /// @brief 复合类型
            Compound,

            /// @brief 引用类型
            Reference,

            /// @brief 指向非静态成员函数或对象的指针类型
            MemberPointer,

            /// @brief 总数
            CTCount,
        };
    } // namespace TypeInfoEnum

} // namespace ntl

#endif