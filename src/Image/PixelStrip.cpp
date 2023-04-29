#ifndef __NEUTRONTL_BITMAP_PIXELSTRIP_CPP__
#define __NEUTRONTL_BITMAP_PIXELSTRIP_CPP__

#include "PixelStrip.hpp"
#include "../Exception/OutOfRangeException.hpp"
#include "../Exception/CaughtException.hpp"
#include "../Maths/MathsUtils.hpp"

namespace ntl
{
    template <typename m_PixelType, bool m_by_row>
    PixelStrip<m_PixelType, m_by_row>::PixelStrip(
        typename PixelStrip<m_PixelType, m_by_row>::BitmapType &bitmap,
        SizeT number)
        : m_bitmap(bitmap),
          m_number(number) {}

    template <typename m_PixelType, bool m_by_row>
    typename PixelStrip<m_PixelType, m_by_row>::PixelType &
    PixelStrip<m_PixelType, m_by_row>::operator[](
        SizeT index)
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
                NTL_MAKE_STATEMENT_INFO("template <typename m_PixelType, bool m_by_row> typename PixelStrip<m_PixelType, m_by_row>::PixelType &PixelStrip<m_PixelType, m_by_row>::operator[](SizeT index)"));
        }
    }

    template <typename m_PixelType, bool m_by_row>
    const typename PixelStrip<m_PixelType, m_by_row>::PixelType &
    PixelStrip<m_PixelType, m_by_row>::operator[](
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
                NTL_MAKE_STATEMENT_INFO("template <typename m_PixelType, bool m_by_row> const typename PixelStrip<m_PixelType, m_by_row>::PixelType &PixelStrip<m_PixelType, m_by_row>::operator[](SizeT index) const"));
        }
    }

    template <typename m_PixelType, bool m_by_row>
    typename PixelStrip<m_PixelType, m_by_row>::BitmapType &
    PixelStrip<m_PixelType, m_by_row>::get_bitmap()
    {
        return m_bitmap;
    }

    template <typename m_PixelType, bool m_by_row>
    const typename PixelStrip<m_PixelType, m_by_row>::BitmapType &
    PixelStrip<m_PixelType, m_by_row>::get_bitmap() const
    {
        return m_bitmap;
    }

    template <typename m_PixelType, bool m_by_row>
    SizeT
    PixelStrip<m_PixelType, m_by_row>::get_number() const
    {
        return m_number;
    }

    template <typename m_PixelType, bool m_by_row>
    typename PixelStrip<m_PixelType, m_by_row>::PixelType &
    PixelStrip<m_PixelType, m_by_row>::get_pixel(
        SizeT index,
        bool repeat)
    {
        try
        {
            if (m_by_row)
            {
                if (repeat)
                    return operator[](cut_off(
                        index, static_cast<SizeT>(0), m_bitmap.get_width()));
                else
                    return operator[](index);
            }
            else
            {
                if (repeat)
                    return operator[](cut_off(
                        index, static_cast<SizeT>(0), m_bitmap.get_height()));
                else
                    return operator[](index);
            }
        }
        catch (const ntl::CaughtException &exception)
        {
            throw CaughtException(
                exception,
                NTL_MAKE_STATEMENT_INFO("template <typename m_PixelType, bool m_by_row> typename PixelStrip<m_PixelType, m_by_row>::PixelType &PixelStrip<m_PixelType, m_by_row>::get_pixel(SizeT index,bool repeat)"));
        }
    }

    template <typename m_PixelType, bool m_by_row>
    const typename PixelStrip<m_PixelType, m_by_row>::PixelType &
    PixelStrip<m_PixelType, m_by_row>::get_pixel(
        SizeT index,
        bool repeat) const
    {
        try
        {
            if (m_by_row)
            {
                if (repeat)
                    return operator[](cut_off(
                        index, static_cast<SizeT>(0), m_bitmap.get_width()));
                else
                    return operator[](index);
            }
            else
            {
                if (repeat)
                    return operator[](cut_off(
                        index, static_cast<SizeT>(0), m_bitmap.get_height()));
                else
                    return operator[](index);
            }
        }
        catch (const ntl::CaughtException &exception)
        {
            throw CaughtException(
                exception,
                NTL_MAKE_STATEMENT_INFO("template <typename m_PixelType, bool m_by_row> const typename PixelStrip<m_PixelType, m_by_row>::PixelType &PixelStrip<m_PixelType, m_by_row>::get_pixel(SizeT index,bool repeat) const"));
        }
    }

    template <typename m_PixelType, bool m_by_row>
    bool
    PixelStrip<m_PixelType, m_by_row>::is_by_row()
    {
        return m_by_row;
    }

} // namespace ntl

#endif
