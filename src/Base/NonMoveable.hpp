#ifndef __NEUTRONTL_BASE_NONMOVEABLE_HPP__
#define __NEUTRONTL_BASE_NONMOVEABLE_HPP__

#include "NonCopyable.hpp"

namespace ntl
{
    /// @brief 不可移动的对象，但是也不能拷贝
    class NTL_ALIGN NonMoveable : public NonCopyable
    {
    public:
        using SelfType = NonMoveable;
        using ParentType = NonCopyable;

    protected:
        constexpr NonMoveable() noexcept = default;
        ~NonMoveable() = default;

    public:
        constexpr explicit NonMoveable(const SelfType &&from) noexcept = delete;
        constexpr SelfType &operator=(const SelfType &&from) noexcept = delete;
    };

} // namespace ntl

#endif