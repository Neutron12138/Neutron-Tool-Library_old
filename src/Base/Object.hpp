#ifndef __NEUTRONTL_BASE_OBJECT_HPP__
#define __NEUTRONTL_BASE_OBJECT_HPP__

#include <string>
#include "BasicObject.hpp"
#include "Type.hpp"

namespace ntl
{
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
        inline constexpr SelfType &operator=(const SelfType &from) noexcept = default;

    public:
        /// @brief 转换为字符串
        /// @return 转换后的结果
        virtual String as_string() const;
    };
} // namespace ntl

#endif
