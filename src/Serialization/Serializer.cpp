#ifndef __NEUTRONTL_SERIALIZATION_SERIALIZER_CPP__
#define __NEUTRONTL_SERIALIZATION_SERIALIZER_CPP__

#include "Serializer.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    Serialization
    serialize(
        const Serializable &object)
    {
        return object.serialize();
    }

    Serialization
    serialize(
        char value)
    {
        return Serialization(StringUtils::to_string(static_cast<int>(value)));
    }

    template <typename ValueType>
    Serialization
    serialize(
        const ValueType &value)
    {
        return Serialization(StringUtils::to_string(value));
    }

    template <typename CharTraitsType, typename AllocatorType>
    Serialization
    serialize(
        const std::basic_string<Char, CharTraitsType, AllocatorType> &str)
    {
        ntl::StringStream sstr;
        sstr << "\"" << ntl::String(str.cbegin(), str.cend()) << "\"";
        return Serialization(sstr.str());
    }

    template <typename ElementType, std::size_t size>
    Serialization
    serialize(
        const std::array<ElementType, size> &container)
    {
        return serialize_container(container.cbegin(), container.cend());
    }

    template <typename ElementType, typename AllocatorType>
    Serialization
    serialize(
        const std::vector<ElementType, AllocatorType> &container)
    {
        return serialize_container(container.cbegin(), container.cend());
    }

    template <typename ElementType>
    Serialization
    serialize(
        const std::initializer_list<ElementType> &container)
    {
        return serialize_container(container.begin(), container.end());
    }

    template <typename IteratorType>
    Serialization
    serialize_container(
        const IteratorType &begin,
        const IteratorType &end)
    {
        ntl::StringStream sstr;
        for (auto iter = begin; iter != end - 1; iter++)
        {
            sstr << serialize(*iter).get_serialization() << ",";
        }
        sstr << serialize(*(end - 1)).get_serialization();
        return Serialization(sstr.str());
    }

    template <typename ElementType>
    Serialization
    serialize_container(
        const ElementType *begin,
        SizeT size)
    {
        ntl::StringStream sstr;
        for (SizeT i = 0; i < size - 1; i++)
        {
            sstr << serialize(begin[i]).get_serialization() << ",";
        }
        sstr << serialize(begin[size - 1]).get_serialization();
        return Serialization(sstr.str());
    }

} // namespace ntl

#endif