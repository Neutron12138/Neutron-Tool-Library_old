#ifndef __NEUTRONTL_MATHS_SPHERE_HPP__
#define __NEUTRONTL_MATHS_SPHERE_HPP__

#include <glm/glm.hpp>
#include "../Base/Object.hpp"

namespace ntl
{
    /// @brief 球体
    class NTL_ALIGN Sphere : public Object
    {
    public:
        using SelfType = Sphere;
        using ParentType = Object;

    public:
        constexpr Sphere() noexcept = default;
        constexpr explicit Sphere(const SelfType &from) noexcept = default;
        ~Sphere() override = default;

    public:
        inline constexpr SelfType &operator=(const SelfType &from) noexcept = default;

    public:
        /// @brief 计算点在直角坐标系上的位置
        /// @param yaw 偏航角
        /// @param pitch 俯仰角
        /// @param distance 与原点的距离
        /// @return 点在直角坐标系上的位置
        static glm::vec3 calc_rcs_position(float yaw, float pitch, float distance = 1.0f);
    };

} // namespace ntl

#endif