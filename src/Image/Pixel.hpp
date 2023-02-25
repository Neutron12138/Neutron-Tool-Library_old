#ifndef __NEUTRONTL_IMAGE_PIXEL_HPP__
#define __NEUTRONTL_IMAGE_PIXEL_HPP__

#include <array>
#include "../Base/Type.hpp"
#include "../Base/BasicObject.hpp"

namespace ntl
{
    /// @brief 基本像素类
    /// @tparam m_ComponentType 分量类型
    /// @tparam m_color_channels 颜色通道总数
    template <typename m_ComponentType, UInt32 m_color_channels>
    class NTL_ALIGN BasicPixel : public BasicObject
    {
    public:
        /// @brief 分量类型
        using ComponentType = m_ComponentType;
        /// @brief 分量持有者
        using ComponentHolder = std::array<ComponentType, m_color_channels>;

        using SelfType = BasicPixel<ComponentType, m_color_channels>;
        using ParentType = BasicObject;

    protected:
        /// @brief 分量
        ComponentHolder m_components;

    public:
        BasicPixel() = default;
        explicit BasicPixel(const ComponentHolder &components);
        explicit BasicPixel(const SelfType &from) = default;
        ~BasicPixel() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
        ComponentType &operator[](UInt32 index);
        const ComponentType &operator[](UInt32 index) const;

    public:
        /// @brief 获取分量
        /// @return 分量
        const ComponentHolder &get_components() const;

        ///
        void set_components(const ComponentHolder &components);

    public:
        /// @brief 获取颜色通道总数
        static UInt32 get_color_channels();
    };

    /// @brief RGB像素
    using PixelRGB = BasicPixel<UInt8, 3>;

    /// @brief 浮点型RGB像素
    using PixelRGBF = BasicPixel<Float32, 3>;

    /// @brief RGBA像素
    using PixelRGBA = BasicPixel<UInt8, 4>;

    /// @brief 浮点型RGBA像素
    using PixelRGBAF = BasicPixel<Float32, 4>;

    /// @brief 灰度像素
    using PixelGrey = BasicPixel<UInt8, 1>;

    /// @brief 灰度+透明度像素
    using PixelGA = BasicPixel<UInt8, 2>;

    /// @brief 普通像素
    using Pixel = PixelRGBA;

} // namespace ntl

#endif