#ifndef __NEUTRONTL_SERIALIZATION_DESERIALIZER_HPP__
#define __NEUTRONTL_SERIALIZATION_DESERIALIZER_HPP__

#include "../Base/Object.hpp"
#include "Serialization.hpp"
#include "../Exception/InvalidArgumentException.hpp"

namespace ntl
{
    /// @brief 反序列化器
    class Deserializer : public Object
    {
    public:
        using SelfType = Deserializer;
        using ParentType = Object;

        /// @brief 整数
        static String regex_is_integer;

        /// @brief 浮点数，形如123
        static String regex_is_float0;

        /// @brief 浮点数，形如123.
        static String regex_is_float1;

        /// @brief 浮点数，形如.123
        static String regex_is_float2;

        /// @brief 浮点数，形如123.123
        static String regex_is_float3;

        /// @brief 是否为字符串，形如"abc"
        static String regex_is_string;

    public:
        Deserializer() = default;
        explicit Deserializer(const SelfType &from) = default;
        ~Deserializer() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        template <typename ResultType>
        static ResultType deserialize(const Serialization &serialization);

        static void deserialize(const Serialization &serialization, Serializable &result);

        static void deserialize(const Serialization &serialization, char &result);

        static void deserialize(const Serialization &serialization, short &result);

        static void deserialize(const Serialization &serialization, int &result);

        static void deserialize(const Serialization &serialization, long &result);

        static void deserialize(const Serialization &serialization, long long &result);

        static void deserialize(const Serialization &serialization, float &result);

        static void deserialize(const Serialization &serialization, double &result);

        template <typename CharTraitsType, typename AllocatorType>
        static void deserialize(const Serialization &serialization, std::basic_string<Char, CharTraitsType, AllocatorType> &result);

        template <typename ElementType>
        static void deserialize(const Serialization &serialization, std::vector<ElementType> &result);

    public:
        /// @brief 生成一个异常
        /// @param type 类型
        /// @return 异常
        static InvalidArgumentException make_exception(const String &type);

        /// @brief 检查是否为整数
        /// @param serialization 序列
        /// @return 是否为整数
        static bool is_integer(const Serialization &serialization);

        /// @brief 检查是否为浮点数
        /// @param serialization 序列
        /// @return 是否为浮点数
        static bool is_float(const Serialization &serialization);

        /// @brief 检查是否为字符串
        /// @param serialization 序列
        /// @return 是否为字符串
        static bool is_string(const Serialization &serialization);
    };

} // namespace ntl

#endif