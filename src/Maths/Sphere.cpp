#ifndef __NEUTRONTL_MATHS_SPHERE_CPP__
#define __NEUTRONTL_MATHS_SPHERE_CPP__

#include "Sphere.hpp"

namespace ntl
{
    NTL_INLINE
    glm::vec3
    Sphere::calc_rcs_position(
        float yaw,
        float pitch,
        float distance)
    {
        float const y = glm::sin(pitch);
        float const h = glm::cos(pitch);
        float const x = glm::cos(yaw) * h;
        float const z = glm::sin(yaw) * h;
        return glm::vec3(x, y, z);
    }

} // namespace ntl

#endif