#ifndef __NEUTRONTL_MISC_ANYTYPE_HPP__
#define __NEUTRONTL_MISC_ANYTYPE_HPP__

#include <bits/move.h>
#include "../Base/BasicObject.hpp"

namespace ntl
{
    /// @brief 可转化为任意类型
    class AnyType : public BasicObject
    {
    public:
        using SelfType = AnyType;
        using ParentType = BasicObject;

    public:
        AnyType() = default;
        explicit AnyType(const SelfType &from) = default;
        ~AnyType() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

        template <typename TargetType>
        operator TargetType() const;

    public:
        template <typename TargetType, typename... ArgsType>
        static TargetType as(ArgsType &&...args);
    };

    namespace cpp20
    {
#if NEUTRONTL_CPP20
        /// @brief 是否能用指定参数构造目标类
        template <typename TargetType, typename... ArgsType>
        concept can_construct =
            requires(ArgsType &&...args) {
                TargetType(std::forward<ArgsType>(args)...);
            };
#endif

    } // namespace cpp20

} // namespace ntl

#endif
