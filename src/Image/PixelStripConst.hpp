#ifndef __NEUTRONTL_IMAGE_PIXELSTRIPCONST_HPP__
#define __NEUTRONTL_IMAGE_PIXELSTRIPCONST_HPP__

#include "../Base/Object.hpp"

namespace ntl
{
    template <typename PixelType>
    class Bitmap;

    /// @brief 像素条
    /// @tparam m_PixelType 像素类型
    /// @tparam m_by_row 是否以行的方式获取
    template <typename m_PixelType, bool m_by_row = true>
    class PixelStripConst : public Object
    {
    public:
        using PixelType = m_PixelType;
        using BitmapType = Bitmap<PixelType>;

        using SelfType = PixelStripConst<PixelType, m_by_row>;
        using ParentType = Object;

    protected:
        /// @brief 位图
        const BitmapType &m_bitmap;

        /// @brief 行号/列号
        SizeT m_number;

    public:
        PixelStripConst(const BitmapType &bitmap, SizeT number);
        PixelStripConst(const SelfType &from) = default;
        ~PixelStripConst() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
        const PixelType &operator[](SizeT index) const;

    public:
        const BitmapType &get_bitmap() const;
        SizeT get_number() const;

    public:
        static bool is_by_row();
    };

} // namespace ntl

#endif
