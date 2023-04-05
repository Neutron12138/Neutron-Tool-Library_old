#ifndef __NEUTRONTL_BASE_COMPARABLE_HPP__
#define __NEUTRONTL_BASE_COMPARABLE_HPP__

#include "Object.hpp"

namespace ntl
{
    /// @brief 可比较的对象
    class Comparable : public Object
    {
    public:
        using SelfType = Comparable;
        using ParentType = Object;

    public:
        constexpr Comparable() noexcept = default;
        constexpr explicit Comparable(const SelfType &from) noexcept = default;
        ~Comparable() override = default;

    public:
        constexpr SelfType &operator=(const SelfType &from) noexcept = default;

    public:
        virtual bool operator>(const Comparable &another) = 0;
        virtual bool operator<(const Comparable &another) = 0;
        virtual bool operator>=(const Comparable &another) = 0;
        virtual bool operator<=(const Comparable &another) = 0;
        virtual bool operator==(const Comparable &another) = 0;
        virtual bool operator!=(const Comparable &another) = 0;
    };

} // namespace ntl

#endif