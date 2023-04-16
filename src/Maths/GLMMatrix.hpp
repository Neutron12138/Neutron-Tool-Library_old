#ifndef __NEUTRONTL_MATHS_GLMMATRIX_HPP__
#define __NEUTRONTL_MATHS_GLMMATRIX_HPP__

#include <glm/glm.hpp>
#include "Matrix.hpp"

namespace ntl
{
    //
    // 预定义类型
    //

    template <typename ComponentType>
    using Matrix2x2 = Matrix<ComponentType, 2, 2>;
    template <typename ComponentType>
    using Matrix2x3 = Matrix<ComponentType, 2, 3>;
    template <typename ComponentType>
    using Matrix2x4 = Matrix<ComponentType, 2, 4>;

    template <typename ComponentType>
    using Matrix3x2 = Matrix<ComponentType, 3, 2>;
    template <typename ComponentType>
    using Matrix3x3 = Matrix<ComponentType, 3, 3>;
    template <typename ComponentType>
    using Matrix3x4 = Matrix<ComponentType, 3, 4>;

    template <typename ComponentType>
    using Matrix4x2 = Matrix<ComponentType, 4, 2>;
    template <typename ComponentType>
    using Matrix4x3 = Matrix<ComponentType, 4, 3>;
    template <typename ComponentType>
    using Matrix4x4 = Matrix<ComponentType, 4, 4>;

    template <typename ComponentType>
    using Matrix2 = Matrix2x2<ComponentType>;
    template <typename ComponentType>
    using Matrix3 = Matrix3x3<ComponentType>;
    template <typename ComponentType>
    using Matrix4 = Matrix4x4<ComponentType>;

    //
    // 工具函数
    //

} // namespace ntl

#endif
