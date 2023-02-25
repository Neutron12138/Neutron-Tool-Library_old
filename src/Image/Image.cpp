#ifndef __NEUTRONTL_IMAGE_IMAGE_CPP__
#define __NEUTRONTL_IMAGE_IMAGE_CPP__

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>
#include "Image.hpp"
#include "../Exception/OutOfRangeException.hpp"

namespace ntl
{
	template <typename m_PixelType>
	Image<m_PixelType>::Image(
		UInt32 width,
		UInt32 height)
		: m_width(width),
		  m_height(height),
		  m_pixels(width * height) {}

	template <typename m_PixelType>
	Image<m_PixelType>::Image(
		UInt32 width,
		UInt32 height,
		const PixelHolder &pixels)
		: m_width(width),
		  m_height(height),
		  m_pixels(pixels) {}

	template <typename m_PixelType>
	typename Image<m_PixelType>::PixelType &
	Image<m_PixelType>::operator[](
		UInt32 index)
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
					"template <typename m_PixelType> typename Image<m_PixelType>::PixelType &Image<m_PixelType>::operator[](UInt32 index)"));
		}
	}

	template <typename m_PixelType>
	const typename Image<m_PixelType>::PixelType &
	Image<m_PixelType>::operator[](
		UInt32 index) const
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
					"template <typename m_PixelType> const typename Image<m_PixelType>::PixelType &Image<m_PixelType>::operator[](UInt32 index) const"));
		}
	}

	template <typename m_PixelType>
	const typename Image<m_PixelType>::PixelHolder &
	Image<m_PixelType>::get_pixels() const
	{
		return m_pixels;
	}

	template <typename m_PixelType>
	std::uint32_t
	Image<m_PixelType>::get_width() const
	{
		return m_width;
	}

	template <typename m_PixelType>
	std::uint32_t
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
		UInt32 width,
		UInt32 height,
		void *source)
	{
		if (source == nullptr)
			throw NullPointerException(
				NTL_STRING(
					"bool Image::load_from_memory(UInt32 width,UInt32 height,void *source)"));

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

} // namespace ntl

#endif