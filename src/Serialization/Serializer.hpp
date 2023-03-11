#ifndef __NEUTRONTL_SERIALIZATION_SERIALIZER_HPP__
#define __NEUTRONTL_SERIALIZATION_SERIALIZER_HPP__

#include <array>
#include <vector>
#include <initializer_list>
#include "../Base/Object.hpp"
#include "Serialization.hpp"

namespace ntl
{
    /// @brief 序列化器
    class NTL_ALIGN Serializer : public Object
    {
    public:
        using SelfType = Serializer;
        using ParentType = Object;

    public:
        Serializer() = default;
        explicit Serializer(const SelfType &from) = default;
        ~Serializer() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        static Serialization serialize(const Serializable &object);

        static Serialization serialize(char value);

        template <typename ValueType>
        static Serialization serialize(const ValueType &value);

        template <typename CharTraitsType, typename AllocatorType>
        static Serialization serialize(const std::basic_string<Char, CharTraitsType, AllocatorType> &str);

        template <typename ElementType, std::size_t size>
        static Serialization serialize(const std::array<ElementType, size> &container);

        template <typename ElementType, typename AllocatorType>
        static Serialization serialize(const std::vector<ElementType, AllocatorType> &container);

        template <typename ElementType>
        static Serialization serialize(const std::initializer_list<ElementType> &container);

        template <typename IteratorType>
        static Serialization serialize_container(const IteratorType &begin, const IteratorType &end);

        template <typename ElementType>
        static Serialization serialize_container(const ElementType *begin, SizeT size);
    };

} // namespace ntl

#endif