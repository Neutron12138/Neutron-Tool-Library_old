#ifndef __NEUTRONTL_BASE_OBJECT_HPP__
#define __NEUTRONTL_BASE_OBJECT_HPP__

#include <string>
#include "BasicObject.hpp"
#include "Type.hpp"

namespace ntl
{
    class Serialization;

    /// @brief 对象类，有虚函数表
    class NTL_ALIGN Object : public BasicObject
    {
    public:
        /// @brief 自身类型
        using SelfType = Object;
        /// @brief 基类类型
        using ParentType = BasicObject;

    public:
        constexpr Object() noexcept = default;
        constexpr explicit Object(const SelfType &from) noexcept = default;
        virtual ~Object() = default;

    public:
        constexpr SelfType &operator=(const SelfType &from) noexcept = default;
    };

    Serialization serialize(const Object &object);

} // namespace ntl

#endif
