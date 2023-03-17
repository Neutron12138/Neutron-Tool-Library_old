#ifndef __NEUTRONTL_MISC_CONTAINEROPERATION_CPP__
#define __NEUTRONTL_MISC_CONTAINEROPERATION_CPP__

#include "ContainerOperation.hpp"

namespace ntl
{
    template <typename ContainerType>
    ContainerType
    ContainerOperation::merge(
        const ContainerType &container,
        const ContainerType &another)
    {
        return merge(container, another.cbegin(), another.cend());
    }

    template <typename ContainerType, typename IteratorType>
    ContainerType
    ContainerOperation::merge(
        const ContainerType &container,
        const IteratorType &begin,
        const IteratorType &end)
    {
        ContainerType result = container;
        for (auto iter = begin; iter != end; iter++)
            result.push_back(*iter);
        return result;
    }

    template <typename KeyType, typename ValueType, typename IteratorType>
    std::map<KeyType, ValueType>
    ContainerOperation::merge(
        const std::map<KeyType, ValueType> &container,
        const IteratorType &begin,
        const IteratorType &end)
    {
        using ContainerType = std::map<KeyType, ValueType>;

        ContainerType result = container;
        for (auto iter = begin; iter != end; iter++)
            result.insert(*iter);
        return result;
    }

} // namespace ntl

#endif