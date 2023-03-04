#ifndef __NEUTRONTL_BASE_SERIALIZABLE_HPP__
#define __NEUTRONTL_BASE_SERIALIZABLE_HPP__

#include "../Base/Object.hpp"

namespace ntl
{
    class Serialization;

    /// @brief 可序列化的对象
    class Serializable : public Object
    {
    public:
        using SelfType = Serializable;
        using ParentType = Object;

    public:
        constexpr Serializable() noexcept = default;
        constexpr explicit Serializable(const SelfType &from) noexcept = default;
        ~Serializable() override = default;

    public:
        constexpr SelfType &operator=(const SelfType &from) noexcept = default;

    public:
        /// @brief 序列化本对象
        /// @return 序列
        virtual Serialization serialize() = 0;

        /// @brief 序列化本对象
        /// @return 序列
        virtual Serialization serialize() const = 0;

        /// @brief 反序列化至本对象
        /// @param serialization 序列
        /// @return 本对象
        virtual SelfType &deserialize(const Serialization &serialization) = 0;
    };

} // namespace ntl

#endif