#ifndef __NEUTRONTL_IMAGE_BITMAP_HPP__
#define __NEUTRONTL_IMAGE_BITMAP_HPP__

#include <string>
#include <vector>
#include <stb/stb_image.h>
#include <stb/stb_image_write.h>
#include "../Base/Object.hpp"
#include "Pixel.hpp"

namespace ntl
{
    /// @brief 位图类
    template <typename m_PixelType>
    class Bitmap : public Object
    {
    public:
        using PixelType = m_PixelType;
        using PixelHolder = std::vector<PixelType>;

        using SelfType = Bitmap<PixelType>;
        using ParentType = Object;

    protected:
        /// @brief 图像数据
        PixelHolder m_pixels;

        /// @brief 图像的宽
        SizeT m_width = 0;

        /// @brief 图像的高
        SizeT m_height = 0;

    public:
        constexpr Bitmap() = default;
        explicit Bitmap(SizeT width, SizeT height);
        explicit Bitmap(SizeT width, SizeT height, const PixelHolder &pixels);
        constexpr explicit Bitmap(const SelfType &from) = default;
        ~Bitmap() override = default;

    public:
        constexpr SelfType &operator=(const SelfType &from);
        PixelType &operator[](SizeT index);
        const PixelType &operator[](SizeT index) const;

    public:
        /// @brief 获取图像的数据
        /// @return 图像数据
        const PixelHolder &get_pixels() const;

        /// @brief 获取像素
        /// @param x 横坐标（以左上角为原点）
        /// @param y 纵坐标（以左上角为原点）
        /// @param repeat 重复，如果为真，则x/y超出后会回到第一个/最后一个像素
        /// @return 像素
        PixelType &get_pixel(SizeT x, SizeT y, bool repeat = true);

        /// @brief 获取像素
        /// @param x 横坐标（以左上角为原点）
        /// @param y 纵坐标（以左上角为原点）
        /// @param repeat 重复，如果为真，则x/y超出后会回到第一个/最后一个像素
        /// @return 像素
        const PixelType &get_pixel(SizeT x, SizeT y, bool repeat = true) const;

        /// @brief 获取图像宽度
        /// @return 图像的宽
        SizeT get_width() const;

        /// @brief 获取图像高度
        /// @return 图像的高
        SizeT get_height() const;

    public:
        /// @brief 手动释放图像资源
        virtual void release();

    public:
        /// @brief 从文件加载图像
        /// @param filename 文件名
        /// @return 是否加载成功
        virtual bool load_from_file(const std::string &filename);

        /// @brief 从内存加载图像
        /// @param width 图像的宽度
        /// @param height 图像的高度
        /// @param source 指向图像数据的指针
        /// @return 是否加载成功
        virtual bool load_from_memory(SizeT width, SizeT height, void *source);

        /// @brief 保存为png文件
        /// @param filename 输出文件名
        /// @param need_flip 输出图像时是否将其反转
        virtual void save_as_png(const std::string &filename, bool need_flip = false);

    public:
        /// @brief 把值截断在[0,max)之间
        /// @param value 值
        /// @param max 最大值
        /// @return 值
        static SizeT cut_off(SizeT value, SizeT max);
    };

} // namespace ntl

#endif