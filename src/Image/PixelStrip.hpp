#ifndef __NEUTRONTL_IMAGE_PIXELSTRIP_HPP__
#define __NEUTRONTL_IMAGE_PIXELSTRIP_HPP__

#include "../Base/Object.hpp"

namespace ntl
{
    template <typename PixelType>
    class Bitmap;

    /// @brief 像素条
    /// @tparam m_PixelType 像素类型
    /// @tparam m_by_row 是否以行的方式获取
    template <typename m_PixelType, bool m_by_row = true>
    class PixelStrip : public Object
    {
    public:
        using PixelType = m_PixelType;
        using BitmapType = Bitmap<PixelType>;

        using SelfType = PixelStrip<PixelType, m_by_row>;
        using ParentType = Object;

    protected:
        /// @brief 位图
        BitmapType &m_bitmap;

        /// @brief 行号/列号
        SizeT m_number;

    public:
        explicit PixelStrip(BitmapType &bitmap, SizeT number);
        explicit PixelStrip(const SelfType &from) = default;
        ~PixelStrip() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
        PixelType &operator[](SizeT index);
        const PixelType &operator[](SizeT index) const;

    public:
        BitmapType &get_bitmap();
        const BitmapType &get_bitmap() const;
        SizeT get_number() const;

        PixelType &get_pixel(SizeT index, bool repeat = false);
        const PixelType &get_pixel(SizeT index, bool repeat = false) const;

    public:
        static bool is_by_row();
    };

} // namespace ntl

#endif
