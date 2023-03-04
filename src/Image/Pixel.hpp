#ifndef __NEUTRONTL_IMAGE_PIXEL_HPP__
#define __NEUTRONTL_IMAGE_PIXEL_HPP__

#include <array>
#include "../Base/Type.hpp"
#include "../Base/BasicObject.hpp"
#include "Color.hpp"

namespace ntl
{
    /// @brief 基本像素类
    /// @tparam m_color_channels 颜色通道总数
    template <SizeT m_color_channels>
    class NTL_ALIGN BasicPixel : public BasicObject
    {
    public:
        /// @brief 分量持有者
        using ComponentHolder = std::array<UInt8, m_color_channels>;

        using SelfType = BasicPixel<m_color_channels>;
        using ParentType = BasicObject;

    protected:
        /// @brief 分量
        ComponentHolder m_components;

    public:
        BasicPixel() = default;
        explicit BasicPixel(const ComponentHolder &components);
        explicit BasicPixel(const Color &color);
        explicit BasicPixel(const SelfType &from) = default;
        ~BasicPixel() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
        SelfType &operator=(const Color &color);
        UInt8 &operator[](UInt32 index);
        const UInt8 &operator[](UInt32 index) const;
        operator Color();
        operator Color() const;

    public:
        /// @brief 获取分量
        /// @return 分量
        const ComponentHolder &get_components() const;

        /// @brief 设置分量
        /// @param components 分量
        void set_components(const ComponentHolder &components);

    public:
        /// @brief 获取颜色通道总数
        static UInt32 get_color_channels();
    };

    /// @brief 灰度像素
    using PixelGrey = BasicPixel<1>;

    /// @brief 灰度+透明度像素
    using PixelGA = BasicPixel<2>;

    /// @brief RGB像素
    using PixelRGB = BasicPixel<3>;

    /// @brief RGBA像素
    using PixelRGBA = BasicPixel<4>;

    /// @brief 普通像素
    using Pixel = PixelRGBA;

} // namespace ntl

#endif