#ifndef __NEUTRONTL_SERIALIZATION_DESERIALIZER_CPP__
#define __NEUTRONTL_SERIALIZATION_DESERIALIZER_CPP__

#include "Deserializer.hpp"
#include "../String/StringUtils.hpp"
#include "../Exception/CaughtException.hpp"

namespace ntl
{
    namespace detail
    {
        InvalidArgumentException
        make_exception(
            const String &type)
        {
            return InvalidArgumentException(
                StringUtils::to_string(
                    NTL_STRING("The serialization content is not of "),
                    type,
                    NTL_STRING(" type")),
                StringUtils::to_string(
                    NTL_STRING("template<> "),
                    type,
                    NTL_STRING(" deserialize(const Serialization &serialization)")));
        }

        bool
        is_integer(
            const Serialization &serialization)
        {
            return StringUtils::match(serialization, Regex(regex_is_integer));
        }

        bool
        is_float(
            const Serialization &serialization)
        {
            return StringUtils::match(serialization, Regex(regex_is_float0)) ||
                   StringUtils::match(serialization, Regex(regex_is_float1)) ||
                   StringUtils::match(serialization, Regex(regex_is_float2)) ||
                   StringUtils::match(serialization, Regex(regex_is_float3));
        }

        bool
        is_string(
            const Serialization &serialization)
        {
            return StringUtils::match(serialization, Regex(regex_is_string));
        }

    } // namespace detail

    template <>
    char
    deserialize(
        const Serialization &serialization)
    {
        if (!detail::is_integer(serialization))
            throw detail::make_exception(NTL_STRING("char"));

        return static_cast<char>(StringUtils::to_int(serialization));
    }

    template <>
    short
    deserialize(
        const Serialization &serialization)
    {
        if (!detail::is_integer(serialization))
            throw detail::make_exception(NTL_STRING("short"));

        return static_cast<short>(StringUtils::to_int(serialization));
    }

    template <>
    int
    deserialize(
        const Serialization &serialization)
    {
        if (!detail::is_integer(serialization))
            throw detail::make_exception(NTL_STRING("int"));

        return StringUtils::to_int(serialization);
    }

    template <>
    long
    deserialize(
        const Serialization &serialization)
    {
        if (!detail::is_integer(serialization))
            throw detail::make_exception(NTL_STRING("long"));

        return StringUtils::to_long(serialization);
    }

    template <>
    long long
    deserialize(
        const Serialization &serialization)
    {
        if (!detail::is_integer(serialization))
            throw detail::make_exception(NTL_STRING("long long"));

        return StringUtils::to_llong(serialization);
    }

    template <>
    float
    deserialize(
        const Serialization &serialization)
    {
        if (!detail::is_float(serialization))
            throw detail::make_exception(NTL_STRING("float"));

        return StringUtils::to_float(serialization);
    }

    template <>
    double
    deserialize(
        const Serialization &serialization)
    {
        if (!detail::is_float(serialization))
            throw detail::make_exception(NTL_STRING("double"));

        return StringUtils::to_double(serialization);
    }

    template <>
    String
    deserialize(
        const Serialization &serialization)
    {
        if (!detail::is_string(serialization))
            throw detail::make_exception(NTL_STRING("String"));

        ntl::Match m;
        StringUtils::search(serialization, m, Regex(detail::regex_is_string));

        ntl::String value = m.str(1);

        return value;
    }

    template <typename CharTraitsType, typename AllocatorType>
    std::basic_string<Char, CharTraitsType, AllocatorType>
    deserialize_string(
        const Serialization &serialization)
    {
        try
        {
            ntl::String value = deserialize<String>(serialization);

            return std::basic_string<Char, CharTraitsType, AllocatorType>(
                value.cbegin(),
                value.cend());
        }
        catch (const InvalidArgumentException &exception)
        {
            throw CaughtException(
                exception,
                NTL_STRING("template <typename CharTraitsType, typename AllocatorType> std::basic_string<Char, CharTraitsType, AllocatorType> deserialize_string(const Serialization &serialization)"));
        }
    }

    template <typename ElementType, typename AllocatorType>
    std::vector<ElementType, AllocatorType>
    deserialize_vector(
        const Serialization &serialization)
    {
        std::vector<ElementType, AllocatorType> result;
        const ntl::String str = serialization.get_serialization();

        /*ntl::StringStream sstr;
        bool in_str=false;
        for (auto iter = str.cbegin(); iter != str.cend(); iter++)
        {
            if(*iter==NTL_CHAR('\"'))
        }*/

        std::vector<ntl::String> vec = StringUtils::split(serialization.get_serialization(), NTL_STRING(","));
        // PrintUtils::print_array(std::cout, vec.cbegin(), vec.cend());
        for (auto iter = vec.cbegin(); iter != vec.cend(); iter++)
        {
            result.push_back(deserialize<ElementType>(Serialization(*iter)));
        }

        return result;
    }

} // namespace ntl

#endif