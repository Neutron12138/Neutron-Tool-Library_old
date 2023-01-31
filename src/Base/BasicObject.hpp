#ifndef __NEUTRONTL_BASE_BASICOBJECT_HPP__
#define __NEUTRONTL_BASE_BASICOBJECT_HPP__

#include "../Config.hpp"

namespace ntl
{
    /// @brief 基础对象类，所有NTL对象的基类
    class NTL_ALIGN BasicObject
    {
    public:
        /// @brief 自身类型
        using SelfType = BasicObject;

    public:
        NTL_INLINE NTL_CONSTEXPR BasicObject() NTL_NOEXCEPT = default;
        NTL_INLINE NTL_CONSTEXPR BasicObject(const SelfType &from) NTL_NOEXCEPT = default;
        NTL_INLINE ~BasicObject() NTL_NOEXCEPT = default;

    public:
        NTL_INLINE NTL_CONSTEXPR SelfType &operator=(const SelfType &from) NTL_NOEXCEPT = default;
    };
} // namespace ntl

#endif