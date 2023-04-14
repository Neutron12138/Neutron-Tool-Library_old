#ifndef __NEUTRONTL_BASE_COPYABLE_HPP__
#define __NEUTRONTL_BASE_COPYABLE_HPP__

#include "Object.hpp"

namespace ntl
{
    /// @brief 可拷贝的对象
    class NTL_ALIGN Copyable : public Object
    {
    public:
        using SelfType = Copyable;
        using ParentType = Object;

    public:
        constexpr Copyable() noexcept = default;
        constexpr explicit Copyable(const SelfType &from) noexcept = default;
        ~Copyable() override = default;

    public:
        constexpr SelfType &operator=(const SelfType &from) noexcept = default;

    public:
        /// @brief 复制本对象
        /// @return 复制结果
        virtual SelfType copy() const;

        /// @brief 与另一个对象交换值
        /// @param another 另一个对象
        /// @return 本对象
        virtual SelfType &swap(SelfType &another);
    };

} // namespace ntl

#endif