#ifndef __NEUTRONTL_BASE_BASICOBJECT_HPP__
#define __NEUTRONTL_BASE_BASICOBJECT_HPP__

#include "../Config.hpp"

namespace ntl
{
    class Serialization;

    /// @brief 基础对象类，所有对象的基类
    class NTL_ALIGN BasicObject
    {
    public:
        /// @brief 自身类型
        using SelfType = BasicObject;

        /// @brief 基类类型
        using ParentType = BasicObject;

    public:
        constexpr BasicObject() noexcept = default;
        constexpr explicit BasicObject(const SelfType &from) noexcept = default;
        ~BasicObject() = default;

    public:
        constexpr SelfType &operator=(const SelfType &from) noexcept = default;
    };

    Serialization serialize(const BasicObject &object);

} // namespace ntl

#endif
