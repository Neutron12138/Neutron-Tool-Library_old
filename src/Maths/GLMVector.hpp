#ifndef __NEUTRONTL_MATHS_GLMVECTOR_HPP__
#define __NEUTRONTL_MATHS_GLMVECTOR_HPP__

#include <glm/glm.hpp>
#include "Vector.hpp"

namespace ntl
{
    //
    // 2维向量
    //

    /// @brief 2维向量
    template <typename m_ComponentType>
    class Vector2 : public Vector<m_ComponentType, 2>
    {
    public:
        using ComponentType = m_ComponentType;

        using SelfType = Vector2<ComponentType>;
        using ParentType = Vector<m_ComponentType, 2>;

        /// @brief GLM类型
        using GLMType = glm::detail::tvec2<ComponentType>;

    public:
        Vector2() = default;
        explicit Vector2(const ComponentType &x);
        explicit Vector2(const ComponentType &x,
                         const ComponentType &y);
        explicit Vector2(const GLMType &from);
        explicit Vector2(const SelfType &from) = default;
        ~Vector2() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
        operator GLMType() const;
    };

    //
    // 3维向量
    //

    /// @brief 3维向量
    template <typename m_ComponentType>
    class Vector3 : public Vector<m_ComponentType, 3>
    {
    public:
        using ComponentType = m_ComponentType;

        using SelfType = Vector3<ComponentType>;
        using ParentType = Vector<m_ComponentType, 3>;

        /// @brief GLM类型
        using GLMType = glm::detail::tvec3<ComponentType>;

    public:
        Vector3() = default;
        explicit Vector3(const ComponentType &x);
        explicit Vector3(const ComponentType &x,
                         const ComponentType &y);
        explicit Vector3(const ComponentType &x,
                         const ComponentType &y,
                         const ComponentType &z);
        explicit Vector3(const GLMType &from);
        explicit Vector3(const SelfType &from) = default;
        ~Vector3() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
        operator GLMType() const;
    };

    //
    // 4维向量
    //

    /// @brief 4维向量
    template <typename m_ComponentType>
    class Vector4 : public Vector<m_ComponentType, 4>
    {
    public:
        using ComponentType = m_ComponentType;

        using SelfType = Vector4<ComponentType>;
        using ParentType = Vector<m_ComponentType, 4>;

        /// @brief GLM类型
        using GLMType = glm::detail::tvec4<ComponentType>;

    public:
        Vector4() = default;
        explicit Vector4(const ComponentType &x);
        explicit Vector4(const ComponentType &x,
                         const ComponentType &y);
        explicit Vector4(const ComponentType &x,
                         const ComponentType &y,
                         const ComponentType &z);
        explicit Vector4(const ComponentType &x,
                         const ComponentType &y,
                         const ComponentType &z,
                         const ComponentType &w);
        explicit Vector4(const GLMType &from);
        explicit Vector4(const SelfType &from) = default;
        ~Vector4() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
        operator GLMType() const;
    };

    //
    // 预定义类型
    //

    // 浮点数向量

    using Vector2f = Vector2<float>;
    using Vector3f = Vector3<float>;
    using Vector4f = Vector4<float>;

    // 双精度数向量

    using Vector2d = Vector2<double>;
    using Vector3d = Vector3<double>;
    using Vector4d = Vector4<double>;

    // 有符号整数向量

    using Vector2i = Vector2<int>;
    using Vector3i = Vector3<int>;
    using Vector4i = Vector4<int>;

    // 无符号整数向量

    using Vector2u = Vector2<unsigned int>;
    using Vector3u = Vector3<unsigned int>;
    using Vector4u = Vector4<unsigned int>;

    // 默认的向量

    using Vec2 = Vector2f;
    using Vec3 = Vector3f;
    using Vec4 = Vector4f;

    //
    // 工具函数
    //

    template <typename ComponentType>
    Vector2<ComponentType> make_vector2(const Vector<ComponentType, 2> &another);
    template <typename ComponentType>
    Vector3<ComponentType> make_vector3(const Vector<ComponentType, 3> &another);
    template <typename ComponentType>
    Vector4<ComponentType> make_vector4(const Vector<ComponentType, 4> &another);

} // namespace ntl

#endif
