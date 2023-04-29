#ifndef __NEUTRONTL_IMAGE_BITMAPEDITOR_CPP__
#define __NEUTRONTL_IMAGE_BITMAPEDITOR_CPP__

#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include <stb/stb_image_resize.h>
#include "BitmapEditor.hpp"

namespace ntl
{
    template <typename PixelType>
    void
    BitmapEditor::flip_x(
        Bitmap<PixelType> &result)
    {
        SizeT pivot = result.get_width() / 2;
        SizeT width = result.get_width();
        SizeT height = result.get_height();
        SizeT end_index = width - 1;

        for (SizeT x = 0; x < pivot; x++)
        {
            for (SizeT y = 0; y < height; y++)
            {
                result[y][x].swap(
                    result[y][end_index - x]);
            }
        }
    }

    template <typename PixelType>
    void
    BitmapEditor::flip_y(
        Bitmap<PixelType> &result)
    {
        SizeT pivot = result.get_height() / 2;
        SizeT width = result.get_width();
        SizeT height = result.get_height();
        SizeT end_index = height - 1;

        for (SizeT y = 0; y < pivot; y++)
        {
            for (SizeT x = 0; x < height; x++)
            {
                result[y][x].swap(
                    result[y][end_index - x]);
            }
        }
    }

    template <typename PixelType>
    void
    BitmapEditor::draw_point(
        Bitmap<PixelType> &result,
        SizeT x,
        SizeT y,
        const PixelType &pixel)
    {
    }

    template <typename PixelType>
    void
    BitmapEditor::draw_line(
        Bitmap<PixelType> &result,
        SizeT x0,
        SizeT y0,
        SizeT x1,
        SizeT y1,
        const PixelType &pixel)
    {
    }

    template <typename PixelType>
    Bitmap<PixelType>
    BitmapEditor::stretch(
        const Bitmap<PixelType> &source,
        float scale_x,
        float scale_y)
    {
        Bitmap<PixelType> result(
            static_cast<SizeT>(
                static_cast<float>(
                    source.get_width()) *
                scale_x),
            static_cast<SizeT>(
                static_cast<float>(
                    source.get_height()) *
                scale_y));

        stbir_resize_uint8(
            reinterpret_cast<const unsigned char *>(
                source.get_pixels().data()),
            source.get_width(),
            source.get_height(),
            0,
            reinterpret_cast<unsigned char *>(
                const_cast<PixelType *>(
                    result.get_pixels().data())),
            result.get_width(),
            result.get_height(),
            0,
            PixelType::get_color_channels());

        return Bitmap<PixelType>(result);
    }

    template <typename PixelType, typename ValueType>
    void
    BitmapEditor::rotate(
        Bitmap<PixelType> &result,
        const Angle<ValueType> &angle)
    {
    }

} // namespace ntl

#endif