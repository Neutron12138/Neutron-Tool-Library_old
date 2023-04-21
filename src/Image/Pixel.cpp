#ifndef __NEUTRONTL_IMAGE_PIXEL_CPP__
#define __NEUTRONTL_IMAGE_PIXEL_CPP__

#include "Pixel.hpp"
#include "../Exception/OutOfRangeException.hpp"

namespace ntl
{
    template <typename m_ComponentType, SizeT m_color_channels>
    BasicPixel<m_ComponentType, m_color_channels>::BasicPixel(
        const ComponentHolder &components)
        : m_components(components) {}

    template <typename m_ComponentType, SizeT m_color_channels>
    BasicPixel<m_ComponentType, m_color_channels>::BasicPixel(
        const Color &color)
    {
        operator=(color);
    }

    template <typename m_ComponentType, SizeT m_color_channels>
    typename BasicPixel<m_ComponentType, m_color_channels>::SelfType &
    BasicPixel<m_ComponentType, m_color_channels>::operator=(
        const Color &color)
    {
        if (m_color_channels >= 1)
            m_components.at(0) = static_cast<UInt8>(color.red * 256.0f);
        if (m_color_channels >= 2)
            m_components.at(1) = static_cast<UInt8>(color.green * 256.0f);
        if (m_color_channels >= 3)
            m_components.at(2) = static_cast<UInt8>(color.blue * 256.0f);
        if (m_color_channels >= 4)
            m_components.at(3) = static_cast<UInt8>(color.alpha * 256.0f);
        return *this;
    }

    template <typename m_ComponentType, SizeT m_color_channels>
    UInt8 &
    BasicPixel<m_ComponentType, m_color_channels>::operator[](
        SizeT index)
    {
        try
        {
            UInt8 &
                result =
                    m_components.at(index);
            return result;
        }
        catch (const std::out_of_range &exception)
        {
            throw OutOfRangeException(
                exception,
                NTL_STRING(
                    "template <typename m_ComponentType, SizeT m_color_channels> UInt8 &BasicPixel< m_color_channels>::operator[](SizeT index)"));
        }
    }

    template <typename m_ComponentType, SizeT m_color_channels>
    const UInt8 &
    BasicPixel<m_ComponentType, m_color_channels>::operator[](
        SizeT index) const
    {
        try
        {
            const UInt8 &
                result =
                    m_components.at(index);
            return result;
        }
        catch (const std::out_of_range &exception)
        {
            throw OutOfRangeException(
                exception,
                NTL_STRING(
                    "template <typename m_ComponentType, SizeT m_color_channels> const UInt8 &BasicPixel< m_color_channels>::operator[](SizeT index) const"));
        }
    }

    template <typename m_ComponentType, SizeT m_color_channels>
    BasicPixel<m_ComponentType, m_color_channels>::operator Color()
    {
        Color result;
        if (m_color_channels >= 1)
            result.red = static_cast<float>(result.red) / 256.0f;
        if (m_color_channels >= 2)
            result.green = static_cast<float>(result.green) / 256.0f;
        if (m_color_channels >= 3)
            result.blue = static_cast<float>(result.blue) / 256.0f;
        if (m_color_channels >= 4)
            result.alpha = static_cast<float>(result.alpha) / 256.0f;
        return result;
    }

    template <typename m_ComponentType, SizeT m_color_channels>
    BasicPixel<m_ComponentType, m_color_channels>::operator Color() const
    {
        Color result;
        if (m_color_channels >= 1)
            result.red = static_cast<float>(result.red) / 256.0f;
        if (m_color_channels >= 2)
            result.green = static_cast<float>(result.green) / 256.0f;
        if (m_color_channels >= 3)
            result.blue = static_cast<float>(result.blue) / 256.0f;
        if (m_color_channels >= 4)
            result.alpha = static_cast<float>(result.alpha) / 256.0f;
        return result;
    }

    template <typename m_ComponentType, SizeT m_color_channels>
    const typename BasicPixel<m_ComponentType, m_color_channels>::ComponentHolder &
    BasicPixel<m_ComponentType, m_color_channels>::get_components() const
    {
        return m_components;
    }

    template <typename m_ComponentType, SizeT m_color_channels>
    void
    BasicPixel<m_ComponentType, m_color_channels>::set_components(
        const typename BasicPixel<m_ComponentType, m_color_channels>::ComponentHolder &components)
    {
        m_components = components;
    }

    template <typename m_ComponentType, SizeT m_color_channels>
    typename BasicPixel<m_ComponentType, m_color_channels>::SelfType &
    BasicPixel<m_ComponentType, m_color_channels>::swap(
        typename BasicPixel<m_ComponentType, m_color_channels>::SelfType &another)
    {
        m_components.swap(another.m_components);
        return *this;
    }

    template <typename m_ComponentType, SizeT m_color_channels>
    SizeT
    BasicPixel<m_ComponentType, m_color_channels>::get_color_channels()
    {
        return m_color_channels;
    }

} // namespace ntl

#endif