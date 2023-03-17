#ifndef __NEUTRONTL_BASE_NONCOPYABLE_HPP__
#define __NEUTRONTL_BASE_NONCOPYABLE_HPP__

#include "BasicObject.hpp"

namespace ntl
{
    /// @brief 不可拷贝的对象，但是可以移动构造
    class NTL_ALIGN NonCopyable : public BasicObject
    {
    public:
        using SelfType = NonCopyable;
        using ParentType = BasicObject;

    protected:
        constexpr NonCopyable() noexcept = default;
        ~NonCopyable() = default;

    public:
        constexpr explicit NonCopyable(const SelfType &from) noexcept = delete;
        constexpr SelfType &operator=(const SelfType &from) noexcept = delete;
    };
} // namespace ntl

#endif