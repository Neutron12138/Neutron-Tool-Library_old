#ifndef __NEUTRONTL_IMAGE_COLOR_HPP__
#define __NEUTRONTL_IMAGE_COLOR_HPP__

#include "../Base/BasicObject.hpp"
#include "../Base/Type.hpp"

namespace ntl
{
    /// @brief 颜色类
    class NTL_ALIGN Color : public BasicObject
    {
    public:
        using SelfType = Color;
        using ParentType = BasicObject;

    public:
        /// @brief 红色，索引：0
        float red = 0.0f;

        /// @brief 绿色，索引：1
        float green = 0.0f;

        /// @brief 蓝色，索引：2
        float blue = 0.0f;

        /// @brief 透明度，索引：3
        float alpha = 1.0f;

    public:
        constexpr Color() = default;
        explicit Color(float grey);
        explicit Color(float r, float g, float b, float a = 0.0f);
        constexpr explicit Color(const SelfType &from) = default;
        ~Color() = default;

    public:
        constexpr SelfType &operator=(const SelfType &from) = default;
        float &operator[](SizeT index);
        const float &operator[](SizeT index) const;
    };

} // namespace ntl

#endif