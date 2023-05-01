#ifndef __NEUTRONTL_MISC_CONTAINEROPERATION_HPP__
#define __NEUTRONTL_MISC_CONTAINEROPERATION_HPP__

#include <vector>
#include <map>
#include "../Base/Object.hpp"

namespace ntl
{
    class ContainerOperation : public Object
    {
    public:
        using SelfType = ContainerOperation;
        using ParentType = Object;

    public:
        constexpr ContainerOperation() noexcept = default;
        constexpr ContainerOperation(const SelfType &from) noexcept = default;
        ~ContainerOperation() override = default;

    public:
        constexpr SelfType &operator=(const SelfType &from) noexcept = default;

    public:
        template <typename ContainerType>
        static ContainerType merge(const ContainerType &container, const ContainerType &another);

        template <typename ContainerType, typename IteratorType>
        static ContainerType merge(const ContainerType &container, const IteratorType &begin, const IteratorType &end);

        template <typename KeyType, typename ValueType, typename IteratorType>
        static std::map<KeyType, ValueType> merge(const std::map<KeyType, ValueType> &container, const IteratorType &begin, const IteratorType &end);
    };
} // namespace ntl

#endif