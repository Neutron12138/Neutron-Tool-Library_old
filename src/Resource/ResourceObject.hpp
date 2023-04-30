#ifndef __NEUTRONTL_RESOURCE_RESOURCEOBJECT_HPP__
#define __NEUTRONTL_RESOURCE_RESOURCEOBJECT_HPP__

#include "../Base/Object.hpp"

namespace ntl
{
    /// @brief 资源对象的基类
    class NTL_ALIGN ResourceObject : public Object
    {
    public:
        using SelfType = ResourceObject;
        using ParentType = Object;

    public:
        constexpr ResourceObject() noexcept = default;
        constexpr explicit ResourceObject(const SelfType &from) noexcept = default;
        ~ResourceObject() override = default;

    public:
        constexpr SelfType &operator=(const SelfType &from) noexcept = default;

    public:
        /// @brief 释放所持有的资源
        virtual void release() = 0;
    };

} // namespace ntl

#endif
