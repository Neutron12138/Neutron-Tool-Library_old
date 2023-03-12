#ifndef __NEUTRONTL_IMAGE_BITMAPEDITOR_HPP__
#define __NEUTRONTL_IMAGE_BITMAPEDITOR_HPP__

#include "../Base/Object.hpp"
#include "Bitmap.hpp"
#include "../Maths/Angle.hpp"

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
        static void draw_point(Bitmap<PixelType> &result, SizeT x, SizeT y, const PixelType &pixel);

        template <typename PixelType>
        static void draw_line(Bitmap<PixelType> &result, SizeT x0, SizeT y0, SizeT x1, SizeT y1, const PixelType &pixel);

        template <typename PixelType>
        static Bitmap<PixelType> stretch(const Bitmap<PixelType> &source, float scale_x, float scale_y);

        template <typename PixelType, typename ValueType>
        static void rotate(Bitmap<PixelType> &result, const Angle<ValueType> &angle);
    };

} // namespace ntl

#endif