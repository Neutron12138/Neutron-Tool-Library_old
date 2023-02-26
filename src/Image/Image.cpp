#ifndef __NEUTRONTL_IMAGE_IMAGE_CPP__
#define __NEUTRONTL_IMAGE_IMAGE_CPP__

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>
#include "Image.hpp"
#include "../Exception/OutOfRangeException.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
	template <typename m_PixelType>
	Image<m_PixelType>::Image(
		SizeT width,
		SizeT height)
		: m_width(width),
		  m_height(height),
		  m_pixels(width * height) {}

	template <typename m_PixelType>
	Image<m_PixelType>::Image(
		SizeT width,
		SizeT height,
		const PixelHolder &pixels)
		: m_width(width),
		  m_height(height),
		  m_pixels(pixels) {}

	template <typename m_PixelType>
	typename Image<m_PixelType>::PixelType &
	Image<m_PixelType>::operator[](
		SizeT index)
	{
		try
		{
			typename Image<m_PixelType>::PixelType &
				pixel =
					m_pixels.at(index);
			return pixel;
		}
		catch (const std::out_of_range &exception)
		{
			throw OutOfRangeException(
				exception,
				NTL_STRING(
					"template <typename m_PixelType> typename Image<m_PixelType>::PixelType &Image<m_PixelType>::operator[](SizeT index)"));
		}
	}

	template <typename m_PixelType>
	const typename Image<m_PixelType>::PixelType &
	Image<m_PixelType>::operator[](
		SizeT index) const
	{
		try
		{
			const typename Image<m_PixelType>::PixelType &
				pixel =
					m_pixels.at(index);
			return pixel;
		}
		catch (const std::out_of_range &exception)
		{
			throw OutOfRangeException(
				exception,
				NTL_STRING(
					"template <typename m_PixelType> const typename Image<m_PixelType>::PixelType &Image<m_PixelType>::operator[](SizeT index) const"));
		}
	}

	template <typename m_PixelType>
	const typename Image<m_PixelType>::PixelHolder &
	Image<m_PixelType>::get_pixels() const
	{
		return m_pixels;
	}

	template <typename m_PixelType>
	typename Image<m_PixelType>::PixelType &
	Image<m_PixelType>::get_pixel(
		UInt32 x,
		UInt32 y,
		bool repeat)
	{
		SizeT coord_x = x;
		SizeT coord_y = y;

		if (!repeat)
		{
			if (x < 0 || x >= m_width)
				throw OutOfRangeException(
					StringUtils::to_string(
						NTL_STRING("X is out of range. x: "),
						x,
						NTL_STRING(" but the width is only: "),
						m_width),
					NTL_STRING(
						"template <typename m_PixelType> typename Image<m_PixelType>::PixelType &Image<m_PixelType>::get_pixel(SizeT x,SizeT y,bool repeat)"));

			if (y < 0 || y >= m_height)
				throw OutOfRangeException(
					StringUtils::to_string(
						NTL_STRING("Y is out of range. y: "),
						y,
						NTL_STRING(" but the height is only: "),
						m_height),
					NTL_STRING(
						"template <typename m_PixelType> typename Image<m_PixelType>::PixelType &Image<m_PixelType>::get_pixel(SizeT x,SizeT y,bool repeat)"));
		}
		else
		{
			coord_x = cut_off(x, m_width);
			coord_y = cut_off(y, m_height);
		}

		return operator[](coord_y *m_width + coord_x);
	}

	template <typename m_PixelType>
	const typename Image<m_PixelType>::PixelType &
	Image<m_PixelType>::get_pixel(
		UInt32 x,
		UInt32 y,
		bool repeat) const
	{
		SizeT coord_x = x;
		SizeT coord_y = y;

		if (!repeat)
		{
			if (x < 0 || x >= m_width)
				throw OutOfRangeException(
					StringUtils::to_string(
						NTL_STRING("X is out of range. x: "),
						x,
						NTL_STRING(" but the width is only: "),
						m_width),
					NTL_STRING(
						"template <typename m_PixelType> const typename Image<m_PixelType>::PixelType &Image<m_PixelType>::get_pixel(SizeT x,SizeT y,bool repeat) const"));

			if (y < 0 || y >= m_height)
				throw OutOfRangeException(
					StringUtils::to_string(
						NTL_STRING("Y is out of range. y: "),
						y,
						NTL_STRING(" but the height is only: "),
						m_height),
					NTL_STRING(
						"template <typename m_PixelType> const typename Image<m_PixelType>::PixelType &Image<m_PixelType>::get_pixel(SizeT x,SizeT y,bool repeat) const"));
		}
		else
		{
			coord_x = cut_off(x, m_width);
			coord_y = cut_off(y, m_height);
		}

		return operator[](coord_y *m_width + coord_x);
	}

	template <typename m_PixelType>
	SizeT
	Image<m_PixelType>::get_width() const
	{
		return m_width;
	}

	template <typename m_PixelType>
	SizeT
	Image<m_PixelType>::get_height() const
	{
		return m_height;
	}

	template <typename m_PixelType>
	void
	Image<m_PixelType>::release()
	{
		m_pixels.clear();
	}

	template <typename m_PixelType>
	bool
	Image<m_PixelType>::load_from_file(
		const std::string &filename)
	{
		int width, height, comp;
		stbi_uc *pixels = stbi_load(filename.data(), &width, &height, &comp, 4);

		if (pixels != nullptr)
		{
			m_width = width;
			m_height = height;

			m_pixels.clear();
			m_pixels.resize(width * height);
			memcpy_s(
				m_pixels.data(),
				m_pixels.size() * sizeof(Image<m_PixelType>::PixelType),
				pixels,
				width * height * 4);

			stbi_image_free(pixels);

			return true;
		}
		else
		{
			return false;
		}
	}

	template <typename m_PixelType>
	bool
	Image<m_PixelType>::load_from_memory(
		SizeT width,
		SizeT height,
		void *source)
	{
		if (source == nullptr)
			throw NullPointerException(
				NTL_STRING(
					"bool Image::load_from_memory(SizeT width,SizeT height,void *source)"));

		m_width = width;
		m_height = height;

		m_pixels.clear();
		m_pixels.resize(width * height);
		memcpy_s(
			m_pixels.data(),
			m_pixels.size() * sizeof(Image<m_PixelType>::PixelType),
			source,
			width * height * 4);

		return true;
	}

	template <typename m_PixelType>
	void
	Image<m_PixelType>::save_as_png(
		const std::string &filename,
		bool need_flip)
	{
		stbi_flip_vertically_on_write(need_flip);

		stbi_write_png(
			filename.data(),
			m_width,
			m_height,
			Image<m_PixelType>::PixelType::get_color_channels(),
			m_pixels.data(),
			0);
	}

	template <typename m_PixelType>
	SizeT
	Image<m_PixelType>::cut_off(
		UInt32 value,
		SizeT max)
	{
		UInt32 result = value;

		if (result < 0)
		{
			result %= max;
			result += max;
		}
		else if (result >= max)
		{
			result %= max;
		}

		return static_cast<SizeT>(result);
	}

} // namespace ntl

#endif