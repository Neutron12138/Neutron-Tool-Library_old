#ifndef __NEUTRONTL_RESOURCE_RESOURCEDELETER_HPP__
#define __NEUTRONTL_RESOURCE_RESOURCEDELETER_HPP__

#include "../Memory/BasicDeleter.hpp"
#include "ResourceObject.hpp"

namespace ntl
{
    // 资源删除器没有数组特化型
    // 因为无法指明具体要删除的元素个数
    // 请使用std::vector之类的代替

    /// @brief 资源删除器
    /// @tparam m_ResourceObjectType 资源对象类型
    template <typename m_ResourceObjectType>
    class ResourceDeleter : public BasicDeleter<m_ResourceObjectType>
    {
    public:
        using ResourceObjectType = m_ResourceObjectType;
        using SelfType = ResourceDeleter<ResourceObjectType>;
        using ParentType = BasicDeleter<ResourceObjectType>;

    public:
        ResourceDeleter() = default;
        ResourceDeleter(const SelfType &from) = default;
        ~ResourceDeleter() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
        virtual void operator()(ResourceObjectType *ptr);
    };

} // namespace ntl

#endif