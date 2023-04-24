#ifndef __NEUTRONTL_SERIALIZATION_SERIALIZER_HPP__
#define __NEUTRONTL_SERIALIZATION_SERIALIZER_HPP__

#include <array>
#include <vector>
#include <initializer_list>
#include "../Base/Object.hpp"
#include "Serialization.hpp"

namespace ntl
{

    Serialization serialize(char value);

    template <typename ValueType>
    Serialization serialize(const ValueType &value);

    template <typename CharTraitsType, typename AllocatorType>
    Serialization serialize(const std::basic_string<Char, CharTraitsType, AllocatorType> &str);

    template <typename ElementType, std::size_t size>
    Serialization serialize(const std::array<ElementType, size> &container);

    template <typename ElementType, typename AllocatorType>
    Serialization serialize(const std::vector<ElementType, AllocatorType> &container);

    template <typename ElementType>
    Serialization serialize(const std::initializer_list<ElementType> &container);

    template <typename IteratorType>
    Serialization serialize_container(const IteratorType &begin, const IteratorType &end);

    template <typename ElementType>
    Serialization serialize_container(const ElementType *begin, SizeT size);

} // namespace ntl

#endif