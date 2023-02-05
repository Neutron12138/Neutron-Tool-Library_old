#ifndef __NEUTRONTL_BASE_TYPE_HPP__
#define __NEUTRONTL_BASE_TYPE_HPP__

#include "BaseDataType.hpp"
#include "StdIOType.hpp"

namespace ntl
{
    // 数据类型

    /// @brief 字节类型
    using Byte = signed char;

    /// @brief 无符号字节类型
    using UByte = unsigned char;

    /// @brief 短整数类型
    using Short = signed short;

    /// @brief 无符号短整数类型
    using UShort = unsigned short;

    /// @brief 整数类型
    using Int = signed int;

    /// @brief 无符号整数类型
    using UInt = unsigned int;

    /// @brief 长整数类型
    using Long = signed long;

    /// @brief 无符号长整数类型
    using ULong = unsigned long;

    /// @brief 超长长整数类型
    using LLong = signed long long;

    /// @brief 无符号超长长整数类型
    using ULLong = unsigned long long;

    /// @brief 浮点数类型
    using Float = float;

    /// @brief 双精度数类型
    using Double = double;

} // namespace ntl

#endif