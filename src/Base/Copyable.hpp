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

    namespace cpp20
    {
#if NEUTRONTL_CPP20
        /// @brief 可拷贝的类型
        template <typename T>
        concept CopyableType =
            requires(T object, T another) {
                // 拥有拷贝构造函数

                // 拥有copy()函数且返回另一个对象
                another = T(object.copy());

                // 拥有swap()函数且返回对象，但不一定是本对象
                object.swap(another);
            };
#endif

    } // namespace cpp20

} // namespace ntl

#endif