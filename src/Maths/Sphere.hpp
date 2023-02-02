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
        NTL_CONSTEXPR Sphere() NTL_NOEXCEPT = default;
        NTL_CONSTEXPR NTL_EXPLICIT Sphere(const SelfType &from) NTL_NOEXCEPT = default;
        ~Sphere() NTL_OVERRIDE = default;

    public:
        NTL_INLINE NTL_CONSTEXPR SelfType &operator=(const SelfType &from) NTL_NOEXCEPT = default;

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