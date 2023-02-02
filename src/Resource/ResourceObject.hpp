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
        NTL_INLINE NTL_CONSTEXPR ResourceObject() NTL_NOEXCEPT = default;
        NTL_INLINE NTL_CONSTEXPR ResourceObject(const SelfType &from) NTL_NOEXCEPT = default;
        NTL_INLINE ~ResourceObject() NTL_NOEXCEPT = default;

    public:
        NTL_INLINE NTL_CONSTEXPR SelfType &operator=(const SelfType &from) NTL_NOEXCEPT = default;

    public:
        /// @brief 释放所持有的资源
        virtual void release() = 0;
    };

} // namespace ntl

#endif