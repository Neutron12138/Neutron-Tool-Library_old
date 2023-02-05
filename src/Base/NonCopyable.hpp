#ifndef __NEUTRONTL_BASE_NONCOPYABLE_HPP__
#define __NEUTRONTL_BASE_NONCOPYABLE_HPP__

#include "Object.hpp"

namespace ntl
{
    /// @brief 不可拷贝的对象，但是可以移动构造
    class NTL_ALIGN NonCopyable : public Object
    {
    public:
        using SelfType = NonCopyable;
        using ParentType = Object;

    protected:
        constexpr NonCopyable() noexcept = default;
        ~NonCopyable() override = default;

    public:
        constexpr explicit NonCopyable(const SelfType &from) noexcept = delete;
        inline constexpr SelfType &operator=(const SelfType &from) noexcept = delete;
    };
} // namespace ntl

#endif