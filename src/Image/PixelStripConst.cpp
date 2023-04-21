#ifndef __NEUTRONTL_BITMAP_PIXELSTRIPCONST_CPP__
#define __NEUTRONTL_BITMAP_PIXELSTRIPCONST_CPP__

#include "PixelStripConst.hpp"
#include "../Exception/OutOfRangeException.hpp"
#include "../Exception/CaughtException.hpp"

namespace ntl
{
    template <typename m_PixelType, bool m_by_row>
    PixelStripConst<m_PixelType, m_by_row>::PixelStripConst(
        const typename PixelStripConst<m_PixelType, m_by_row>::BitmapType &bitmap,
        SizeT number)
        : m_bitmap(bitmap),
          m_number(number) {}

    template <typename m_PixelType, bool m_by_row>
    const typename PixelStripConst<m_PixelType, m_by_row>::PixelType &
    PixelStripConst<m_PixelType, m_by_row>::operator[](
        SizeT index) const
    {
        try
        {
            if (m_by_row)
                return m_bitmap.get_pixel(
                    m_number * m_bitmap.get_width() + index);
            else
                return m_bitmap.get_pixel(
                    index * m_bitmap.get_width() + m_number);
        }
        catch (const ntl::OutOfRangeException &exception)
        {
            throw CaughtException(
                exception,
                NTL_STRING("template <typename m_PixelType, bool m_by_row> const typename PixelStripConst<m_PixelType, m_by_row>::PixelType &PixelStripConst<m_PixelType, m_by_row>::operator[](SizeT index) const"));
        }
    }

    template <typename m_PixelType, bool m_by_row>
    const typename PixelStripConst<m_PixelType, m_by_row>::BitmapType &
    PixelStripConst<m_PixelType, m_by_row>::get_bitmap() const
    {
        return m_bitmap;
    }

    template <typename m_PixelType, bool m_by_row>
    SizeT
    PixelStripConst<m_PixelType, m_by_row>::get_number() const
    {
        return m_number;
    }

    template <typename m_PixelType, bool m_by_row>
    bool
    PixelStripConst<m_PixelType, m_by_row>::is_by_row()
    {
        return m_by_row;
    }

} // namespace ntl

#endif
