#ifndef __NEUTRONTL_REFLECTION_REFLECTIBLE_HPP__
#define __NEUTRONTL_REFLECTION_REFLECTIBLE_HPP__

#include "../Base/Object.hpp"

namespace ntl
{
    class Details;

    /// @brief 可反射的对象
    class Reflectible : public Object
    {
    public:
        using SelfType = Reflectible;
        using ParentType = Object;

    public:
        constexpr Reflectible() noexcept = default;
        constexpr explicit Reflectible(const SelfType &from) noexcept = default;
        ~Reflectible() override = default;

    public:
        constexpr SelfType &operator=(const SelfType &from) noexcept = default;

    public:
        /// @brief 获取反射的细节
        /// @return 反射的细节
        static Details get_reflection_details();

        /// @brief 构造一个可反射的对象
        /// @return 内存地址
        static Reflectible *construct();

        /// @brief 析构一个可反射的对象
        /// @param ptr 内存地址
        static void destruct(Byte *ptr);
    };

} // namespace ntl

#endif