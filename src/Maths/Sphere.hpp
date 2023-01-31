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
        NTL_INLINE constexpr Sphere() NTL_NOEXCEPT = default;
        NTL_INLINE constexpr Sphere(const SelfType &from) NTL_NOEXCEPT = default;
        NTL_INLINE ~Sphere() NTL_NOEXCEPT = default;

    public:
        NTL_INLINE constexpr SelfType &operator=(const SelfType &from) NTL_NOEXCEPT = default;

    public:
        /// @brief 计算点在直角坐标系上的位置
        /// @param yaw 偏航角
        /// @param pitch 俯仰角
        /// @param distance 与原点的距离
        /// @return 点在直角坐标系上的位置
        NTL_INLINE static glm::vec3 calc_rcs_position(float yaw, float pitch, float distance = 1.0f);
    };

} // namespace ntl

#endif