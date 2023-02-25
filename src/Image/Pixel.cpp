#ifndef __NEUTRONTL_IMAGE_PIXEL_CPP__
#define __NEUTRONTL_IMAGE_PIXEL_CPP__

#include "Pixel.hpp"
#include "../Exception/OutOfRangeException.hpp"

namespace ntl
{
    template <typename m_ComponentType, UInt32 m_color_channels>
    BasicPixel<m_ComponentType, m_color_channels>::BasicPixel(
        const ComponentHolder &components)
        : m_components(components) {}

    template <typename m_ComponentType, UInt32 m_color_channels>
    typename BasicPixel<m_ComponentType, m_color_channels>::ComponentType &
    BasicPixel<m_ComponentType, m_color_channels>::operator[](
        UInt32 index)
    {
        try
        {
            typename BasicPixel<m_ComponentType, m_color_channels>::ComponentType &
                result =
                    m_components.at(index);
            return result;
        }
        catch (const std::out_of_range &exception)
        {
            throw OutOfRangeException(
                exception,
                NTL_STRING(
                    "template <typename m_ComponentType, UInt32 m_color_channels> typename BasicPixel<m_ComponentType, m_color_channels>::ComponentType &BasicPixel<m_ComponentType, m_color_channels>::operator[](UInt32 index)"));
        }
    }

    template <typename m_ComponentType, UInt32 m_color_channels>
    const typename BasicPixel<m_ComponentType, m_color_channels>::ComponentType &
    BasicPixel<m_ComponentType, m_color_channels>::operator[](
        UInt32 index) const
    {
        try
        {
            const typename BasicPixel<m_ComponentType, m_color_channels>::ComponentType &
                result =
                    m_components.at(index);
            return result;
        }
        catch (const std::out_of_range &exception)
        {
            throw OutOfRangeException(
                exception,
                NTL_STRING(
                    "template <typename m_ComponentType, UInt32 m_color_channels> const typename BasicPixel<m_ComponentType, m_color_channels>::ComponentType &BasicPixel<m_ComponentType, m_color_channels>::operator[](UInt32 index) const"));
        }
    }

    template <typename m_ComponentType, UInt32 m_color_channels>
    const typename BasicPixel<m_ComponentType, m_color_channels>::ComponentHolder &
    BasicPixel<m_ComponentType, m_color_channels>::get_components() const
    {
        return m_components;
    }

    template <typename m_ComponentType, UInt32 m_color_channels>
    void
    BasicPixel<m_ComponentType, m_color_channels>::set_components(
        const typename BasicPixel<m_ComponentType, m_color_channels>::ComponentHolder &components)
    {
        m_components = components;
    }

    template <typename m_ComponentType, UInt32 m_color_channels>
    UInt32
    BasicPixel<m_ComponentType, m_color_channels>::get_color_channels()
    {
        return m_color_channels;
    }

} // namespace ntl

#endif