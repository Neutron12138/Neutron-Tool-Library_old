#ifndef __NEUTRONTL_SERIALIZATION_DESERIALIZER_CPP__
#define __NEUTRONTL_SERIALIZATION_DESERIALIZER_CPP__

#include "Deserializer.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    String Deserializer::regex_is_integer = NTL_STRING("[0-9]+");
    String Deserializer::regex_is_float0 = NTL_STRING("[0-9]+[fd]?");
    String Deserializer::regex_is_float1 = NTL_STRING("[0-9]+.[fd]?");
    String Deserializer::regex_is_float2 = NTL_STRING(".[0-9]+[fd]?");
    String Deserializer::regex_is_float3 = NTL_STRING("[0-9]+.[0-9]+[fd]?");
    String Deserializer::regex_is_string = NTL_STRING("\"(.*)\"");

    template <typename ResultType>
    ResultType
    Deserializer::deserialize(
        const Serialization &serialization)
    {
        ResultType result;
        deserialize(serialization, result);
        return static_cast<ResultType>(result);
    }

    void
    Deserializer::deserialize(
        const Serialization &serialization,
        Serializable &result)
    {
        result.deserialize(serialization);
    }

    void
    Deserializer::deserialize(
        const Serialization &serialization,
        char &result)
    {
        if (!is_integer(serialization))
            throw make_exception(NTL_STRING("char"));

        result = static_cast<char>(StringUtils::to_int(serialization));
    }

    void
    Deserializer::deserialize(
        const Serialization &serialization,
        short &result)
    {
        if (!is_integer(serialization))
            throw make_exception(NTL_STRING("short"));

        result = static_cast<short>(StringUtils::to_int(serialization));
    }

    void
    Deserializer::deserialize(
        const Serialization &serialization,
        int &result)
    {
        if (!is_integer(serialization))
            throw make_exception(NTL_STRING("int"));

        result = StringUtils::to_int(serialization);
    }

    void
    Deserializer::deserialize(
        const Serialization &serialization,
        long &result)
    {
        if (!is_integer(serialization))
            throw make_exception(NTL_STRING("long"));

        result = StringUtils::to_long(serialization);
    }

    void
    Deserializer::deserialize(
        const Serialization &serialization,
        long long &result)
    {
        if (!is_integer(serialization))
            throw make_exception(NTL_STRING("long long"));

        result = StringUtils::to_llong(serialization);
    }

    void
    Deserializer::deserialize(
        const Serialization &serialization,
        float &result)
    {
        if (!is_float(serialization))
            throw make_exception(NTL_STRING("float"));

        result = StringUtils::to_float(serialization);
    }

    void
    Deserializer::deserialize(
        const Serialization &serialization,
        double &result)
    {
        if (!is_float(serialization))
            throw make_exception(NTL_STRING("double"));

        result = StringUtils::to_double(serialization);
    }

    template <typename CharTraitsType, typename AllocatorType>
    void
    Deserializer::deserialize(
        const Serialization &serialization,
        std::basic_string<Char, CharTraitsType, AllocatorType> &result)
    {
        if (!is_string(serialization))
            throw make_exception(NTL_STRING("string"));

        ntl::Match m;
        StringUtils::search(serialization, m, Regex(regex_is_string));

        ntl::String value = m.str(1);
        result =
            std::basic_string<Char, CharTraitsType, AllocatorType>(
                value.cbegin(),
                value.cend());
    }

    template <typename ElementType>
    void
    Deserializer::deserialize(
        const Serialization &serialization,
        std::vector<ElementType> &result)
    {
        const ntl::String str = serialization.get_serialization();

        result.clear();

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
            result.push_back(Deserializer::deserialize<ElementType>(Serialization(*iter)));
        }
    }

    InvalidArgumentException
    Deserializer::make_exception(
        const String &type)
    {
        return InvalidArgumentException(
            StringUtils::to_string(
                NTL_STRING("The serialization content is not of "),
                type,
                NTL_STRING(" type")),
            StringUtils::to_string(
                NTL_STRING("void Deserializer::deserialize("),
                type,
                NTL_STRING(" &result)")));
    }

    bool
    Deserializer::is_integer(
        const Serialization &serialization)
    {
        return StringUtils::match(serialization, Regex(regex_is_integer));
    }

    bool
    Deserializer::is_float(
        const Serialization &serialization)
    {
        return StringUtils::match(serialization, Regex(regex_is_float0)) ||
               StringUtils::match(serialization, Regex(regex_is_float1)) ||
               StringUtils::match(serialization, Regex(regex_is_float2)) ||
               StringUtils::match(serialization, Regex(regex_is_float3));
    }

    bool
    Deserializer::is_string(
        const Serialization &serialization)
    {
        return StringUtils::match(serialization, Regex(regex_is_string));
    }

} // namespace ntl

#endif