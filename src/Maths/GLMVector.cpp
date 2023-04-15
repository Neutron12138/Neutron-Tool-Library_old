#ifndef __NEUTRONTL_MATHS_GLMVECTOR_CPP__
#define __NEUTRONTL_MATHS_GLMVECTOR_CPP__

#include "GLMVector.hpp"

namespace ntl
{
    //
    // 2维向量
    //

    template <typename m_ComponentType>
    Vector2<m_ComponentType>::Vector2(
        const typename Vector2<m_ComponentType>::ComponentType &x)
        : ParentType(
              make_vector<m_ComponentType>(
                  x,
                  0)) {}

    template <typename m_ComponentType>
    Vector2<m_ComponentType>::Vector2(
        const typename Vector2<m_ComponentType>::ComponentType &x,
        const typename Vector2<m_ComponentType>::ComponentType &y)
        : ParentType(
              make_vector<m_ComponentType>(
                  x,
                  y)) {}

    template <typename m_ComponentType>
    Vector2<m_ComponentType>::Vector2(
        const typename Vector2<m_ComponentType>::GLMType &from)
        : ParentType(
              make_vector<m_ComponentType>(
                  from.x,
                  from.y)) {}

    template <typename m_ComponentType>
    Vector2<m_ComponentType>::operator typename Vector2<m_ComponentType>::GLMType() const
    {
        return GLMType(
            ParentType::operator[](0),
            ParentType::operator[](1));
    }

    //
    // 3维向量
    //

    template <typename m_ComponentType>
    Vector3<m_ComponentType>::Vector3(
        const typename Vector3<m_ComponentType>::ComponentType &x)
        : ParentType(
              make_vector<m_ComponentType>(
                  x,
                  0,
                  0)) {}

    template <typename m_ComponentType>
    Vector3<m_ComponentType>::Vector3(
        const typename Vector3<m_ComponentType>::ComponentType &x,
        const typename Vector3<m_ComponentType>::ComponentType &y)
        : ParentType(
              make_vector<m_ComponentType>(
                  x,
                  y,
                  0)) {}

    template <typename m_ComponentType>
    Vector3<m_ComponentType>::Vector3(
        const typename Vector3<m_ComponentType>::ComponentType &x,
        const typename Vector3<m_ComponentType>::ComponentType &y,
        const typename Vector3<m_ComponentType>::ComponentType &z)
        : ParentType(
              make_vector<m_ComponentType>(
                  x,
                  y,
                  z)) {}

    template <typename m_ComponentType>
    Vector3<m_ComponentType>::Vector3(
        const typename Vector3<m_ComponentType>::GLMType &from)
        : ParentType(
              make_vector<m_ComponentType>(
                  from.x,
                  from.y,
                  from.z)) {}

    template <typename m_ComponentType>
    Vector3<m_ComponentType>::operator typename Vector3<m_ComponentType>::GLMType() const
    {
        return GLMType(
            ParentType::operator[](0),
            ParentType::operator[](1),
            ParentType::operator[](2));
    }

    //
    // 4维向量
    //

    template <typename m_ComponentType>
    Vector4<m_ComponentType>::Vector4(
        const typename Vector4<m_ComponentType>::ComponentType &x)
        : ParentType(
              make_vector<m_ComponentType>(
                  x,
                  0,
                  0,
                  0)) {}

    template <typename m_ComponentType>
    Vector4<m_ComponentType>::Vector4(
        const typename Vector4<m_ComponentType>::ComponentType &x,
        const typename Vector4<m_ComponentType>::ComponentType &y)
        : ParentType(
              make_vector<m_ComponentType>(
                  x,
                  y,
                  0,
                  0)) {}

    template <typename m_ComponentType>
    Vector4<m_ComponentType>::Vector4(
        const typename Vector4<m_ComponentType>::ComponentType &x,
        const typename Vector4<m_ComponentType>::ComponentType &y,
        const typename Vector4<m_ComponentType>::ComponentType &z)
        : ParentType(
              make_vector<m_ComponentType>(
                  x,
                  y,
                  z,
                  0)) {}

    template <typename m_ComponentType>
    Vector4<m_ComponentType>::Vector4(
        const typename Vector4<m_ComponentType>::ComponentType &x,
        const typename Vector4<m_ComponentType>::ComponentType &y,
        const typename Vector4<m_ComponentType>::ComponentType &z,
        const typename Vector4<m_ComponentType>::ComponentType &w)
        : ParentType(
              make_vector<m_ComponentType>(
                  x,
                  y,
                  z,
                  w)) {}

    template <typename m_ComponentType>
    Vector4<m_ComponentType>::Vector4(
        const typename Vector4<m_ComponentType>::GLMType &from)
        : ParentType(
              make_vector<m_ComponentType>(
                  from.x,
                  from.y,
                  from.z,
                  from.w)) {}

    template <typename m_ComponentType>
    Vector4<m_ComponentType>::operator Vector4<m_ComponentType>::GLMType() const
    {
        return GLMType(
            ParentType::operator[](0),
            ParentType::operator[](1),
            ParentType::operator[](2),
            ParentType::operator[](3));
    }

    //
    // 工具函数
    //

    template <typename ComponentType>
    Vector2<ComponentType>
    make_vector2(
        const Vector<ComponentType, 2> &another)
    {
        return Vector2<ComponentType>(
            another[0],
            another[1]);
    }

    template <typename ComponentType>
    Vector3<ComponentType>
    make_vector3(
        const Vector<ComponentType, 3> &another)
    {
        return Vector3<ComponentType>(
            another[0],
            another[1],
            another[2]);
    }

    template <typename ComponentType>
    Vector4<ComponentType>
    make_vector4(
        const Vector<ComponentType, 4> &another)
    {
        return Vector4<ComponentType>(
            another[0],
            another[1],
            another[2],
            another[3]);
    }

} // namespace ntl

#endif
