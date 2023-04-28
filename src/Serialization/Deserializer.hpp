#ifndef __NEUTRONTL_SERIALIZATION_DESERIALIZER_HPP__
#define __NEUTRONTL_SERIALIZATION_DESERIALIZER_HPP__

#include "../Base/Object.hpp"
#include "Serialization.hpp"
#include "../Exception/InvalidArgumentException.hpp"

namespace ntl
{
    namespace detail
    {
        /// @brief 整数
        static const String regex_is_integer = NTL_STRING("[0-9]+");

        /// @brief 浮点数，形如123
        static const String regex_is_float0 = NTL_STRING("[0-9]+[fd]?");

        /// @brief 浮点数，形如123.
        static const String regex_is_float1 = NTL_STRING("[0-9]+.[fd]?");

        /// @brief 浮点数，形如.123
        static const String regex_is_float2 = NTL_STRING(".[0-9]+[fd]?");

        /// @brief 浮点数，形如123.123
        static const String regex_is_float3 = NTL_STRING("[0-9]+.[0-9]+[fd]?");

        /// @brief 是否为字符串，形如"abc"
        static const String regex_is_string = NTL_STRING("\"(.*)\"");

        /// @brief 生成一个异常
        /// @param type 类型
        /// @return 异常
        InvalidArgumentException make_exception(const String &type);

        /// @brief 检查是否为整数
        /// @param serialization 序列
        /// @return 是否为整数
        bool is_integer(const Serialization &serialization);

        /// @brief 检查是否为浮点数
        /// @param serialization 序列
        /// @return 是否为浮点数
        bool is_float(const Serialization &serialization);

        /// @brief 检查是否为字符串
        /// @param serialization 序列
        /// @return 是否为字符串
        bool is_string(const Serialization &serialization);

    } // namespace detail

    template <typename ResultType>
    ResultType deserialize(const Serialization &serialization);

    template <typename CharTraitsType = std::char_traits<Char>, typename AllocatorType = std::allocator<Char>>
    std::basic_string<Char, CharTraitsType, AllocatorType> deserialize_string(const Serialization &serialization);

    template <typename ElementType, typename AllocatorType = std::allocator<ElementType>>
    std::vector<ElementType, AllocatorType> deserialize_vector(const Serialization &serialization);

} // namespace ntl

#endif