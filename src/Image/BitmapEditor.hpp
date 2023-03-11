#ifndef __NEUTRONTL_IMAGE_BITMAPEDITOR_HPP__
#define __NEUTRONTL_IMAGE_BITMAPEDITOR_HPP__

#include "../Base/Object.hpp"
#include "Bitmap.hpp"

namespace ntl
{
    /// @brief 位图编辑器
    class BitmapEditor : public Object
    {
    public:
        using SelfType = BitmapEditor;
        using ParentType = Object;

    public:
        constexpr BitmapEditor() noexcept = default;
        constexpr explicit BitmapEditor(const SelfType &from) noexcept = default;
        ~BitmapEditor() override = default;

    public:
        constexpr SelfType &operator=(const SelfType &from) noexcept = default;

    public:
        template <typename PixelType>
        static void flip_x(Bitmap<PixelType> &result);

        template <typename PixelType>
        static void flip_y(Bitmap<PixelType> &result);

        template <typename PixelType>
        static void draw_point(Bitmap<PixelType> &result, const PixelType &pixel);

        template <typename PixelType>
        static void draw_line(Bitmap<PixelType> &result, const PixelType &pixel);

        template <typename PixelType>
        static void stretch(Bitmap<PixelType> &result);
    };

} // namespace ntl

#endif