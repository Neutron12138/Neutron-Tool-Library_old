#ifndef __NEUTRONTL_BASE_BASEDATATYPE_HPP__
#define __NEUTRONTL_BASE_BASEDATATYPE_HPP__

#include <cstdint>

namespace ntl
{
    /// @brief 8位整数类型
    using Int8 = std::int8_t;

    /// @brief 无符号8位整数类型
    using UInt8 = std::uint8_t;

    /// @brief 16位整数类型
    using Int16 = std::int16_t;

    /// @brief 无符号16位整数类型
    using UInt16 = std::uint16_t;

    /// @brief 32位整数类型
    using Int32 = std::int32_t;

    /// @brief 无符号32位整数类型
    using UInt32 = std::uint32_t;

    /// @brief 64位整数类型
    using Int64 = std::int64_t;

    /// @brief 无符号64位整数类型
    using UInt64 = std::uint64_t;

    /// @brief 尺寸类型
    using SizeT = std::size_t;

    /// @brief 32位浮点数
    using Float32 = float;

    /// @brief 64位浮点数
    using Float64 = double;

    /// @brief 128位浮点数
    using Float128 = long double;

    /// @brief 8位字符
    using Char8 = char;

    /// @brief 宽字符
    using CharW = wchar_t;

#ifdef NEUTRONTL_CONFIG_USE_WCHAR
    /// @brief 字符类型
    using Char = wchar_t;
#else
    /// @brief 字符类型
    using Char = char;
#endif

} // namespace ntl

#endif