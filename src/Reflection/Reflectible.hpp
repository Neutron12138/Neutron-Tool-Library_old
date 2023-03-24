#ifndef __NEUTRONTL_REFLECTION_REFLECTIBLE_HPP__
#define __NEUTRONTL_REFLECTION_REFLECTIBLE_HPP__

#include "../Base/BasicObject.hpp"

namespace ntl
{
    class Details;

    /// @brief 可反射的对象
    class NTL_ALIGN Reflectible : public BasicObject
    {
    public:
        using SelfType = Reflectible;
        using ParentType = BasicObject;

    public:
        constexpr Reflectible() noexcept = default;
        constexpr explicit Reflectible(const SelfType &from) noexcept = default;
        ~Reflectible() = default;

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
        static void destruct(Reflectible *ptr);
    };

} // namespace ntl

#endif