#ifndef __NEUTRONTL_RESOURCE_RESOURCEOBJECT_HPP__
#define __NEUTRONTL_RESOURCE_RESOURCEOBJECT_HPP__

#include "../Base/Object.hpp"

namespace ntl
{
    /// @brief 资源对象的基类
    class ResourceObject : public Object
    {
    public:
        using SelfType = ResourceObject;
        using ParentType = Object;

    public:
        ResourceObject() = default;
        ResourceObject(const SelfType &from) = default;
        ~ResourceObject() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        /// @brief 释放所持有的资源
        virtual void release() = 0;
    };

} // namespace ntl

#endif