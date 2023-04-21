#ifndef __NEUTRONTL_IMAGE_BITMAP_CPP__
#define __NEUTRONTL_IMAGE_BITMAP_CPP__

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>
#include "Bitmap.hpp"
#include "../Exception/OutOfRangeException.hpp"
#include "../String/StringUtils.hpp"
#include "../Exception/NullPointerException.hpp"

namespace ntl
{
	template <typename m_PixelType>
	Bitmap<m_PixelType>::Bitmap(
		SizeT width,
		SizeT height)
		: m_width(width),
		  m_height(height),
		  m_pixels(width * height) {}

	template <typename m_PixelType>
	Bitmap<m_PixelType>::Bitmap(
		SizeT width,
		SizeT height,
		const PixelHolder &pixels)
		: m_width(width),
		  m_height(height),
		  m_pixels(pixels) {}

	template <typename m_PixelType>
	typename Bitmap<m_PixelType>::PixelRow
	Bitmap<m_PixelType>::operator[](
		SizeT index)
	{
		try
		{
			return get_row(index);
		}
		catch (const OutOfRangeException &exception)
		{
			throw CaughtException(
				exception,
				NTL_STRING("template <typename m_PixelType> typename Bitmap<m_PixelType>::PixelRow &Bitmap<m_PixelType>::operator[](SizeT index)"));
		}
	}

	template <typename m_PixelType>
	typename Bitmap<m_PixelType>::PixelRowConst
	Bitmap<m_PixelType>::operator[](
		SizeT index) const
	{
		try
		{
			return get_row(index);
		}
		catch (const OutOfRangeException &exception)
		{
			throw OutOfRangeException(
				exception,
				NTL_STRING("template <typename m_PixelType> const typename Bitmap<m_PixelType>::PixelRowConst &Bitmap<m_PixelType>::operator[](SizeT index) const"));
		}
	}

	template <typename m_PixelType>
	const typename Bitmap<m_PixelType>::PixelHolder &
	Bitmap<m_PixelType>::get_pixels() const
	{
		return m_pixels;
	}

	template <typename m_PixelType>
	typename Bitmap<m_PixelType>::PixelType &
	Bitmap<m_PixelType>::get_pixel(
		SizeT index)
	{
		try
		{
			return m_pixels.at(index);
		}
		catch (const std::out_of_range &exception)
		{
			throw OutOfRangeException(
				exception,
				NTL_STRING("template <typename m_PixelType> typename Bitmap<m_PixelType>::PixelType &Bitmap<m_PixelType>::get_pixel(SizeT index)"));
		}
	}

	template <typename m_PixelType>
	const typename Bitmap<m_PixelType>::PixelType &
	Bitmap<m_PixelType>::get_pixel(
		SizeT index) const
	{
		try
		{
			return m_pixels.at(index);
		}
		catch (const std::out_of_range &exception)
		{
			throw OutOfRangeException(
				exception,
				NTL_STRING("template <typename m_PixelType> const typename Bitmap<m_PixelType>::PixelType &Bitmap<m_PixelType>::get_pixel(SizeT index) const"));
		}
	}

	template <typename m_PixelType>
	typename Bitmap<m_PixelType>::PixelRow
	Bitmap<m_PixelType>::get_row(
		SizeT index)
	{
		if (index < m_height)
			return PixelRow(*this, index);
		else
			throw OutOfRangeException(
				StringUtils::to_string(
					NTL_STRING("Index out of range, index: "),
					index,
					NTL_STRING(", bitmap height: "),
					m_height),
				NTL_STRING("template <typename m_PixelType> typename Bitmap<m_PixelType>::PixelRow Bitmap<m_PixelType>::get_row(SizeT index)"));
	}

	template <typename m_PixelType>
	typename Bitmap<m_PixelType>::PixelRowConst
	Bitmap<m_PixelType>::get_row(
		SizeT index) const
	{
		if (index < m_height)
			return PixelRowConst(*this, index);
		else
			throw OutOfRangeException(
				StringUtils::to_string(
					NTL_STRING("Index out of range, index: "),
					index,
					NTL_STRING(", bitmap height: "),
					m_height),
				NTL_STRING("template <typename m_PixelType> typename Bitmap<m_PixelType>::PixelRowConst Bitmap<m_PixelType>::get_row(SizeT index) const"));
	}

	template <typename m_PixelType>
	typename Bitmap<m_PixelType>::PixelColumn
	Bitmap<m_PixelType>::get_column(
		SizeT index)
	{
		if (index < m_width)
			return PixelColumn(*this, index);
		else
			throw OutOfRangeException(
				StringUtils::to_string(
					NTL_STRING("Index out of range, index: "),
					index,
					NTL_STRING(", bitmap width: "),
					m_width),
				NTL_STRING("template <typename m_PixelType> typename Bitmap<m_PixelType>::PixelColumn Bitmap<m_PixelType>::get_column(SizeT index)"));
	}

	template <typename m_PixelType>
	typename Bitmap<m_PixelType>::PixelColumnConst
	Bitmap<m_PixelType>::get_column(
		SizeT index) const
	{
		if (index < m_width)
			return PixelColumnConst(*this, index);
		else
			throw OutOfRangeException(
				StringUtils::to_string(
					NTL_STRING("Index out of range, index: "),
					index,
					NTL_STRING(", bitmap width: "),
					m_width),
				NTL_STRING("template <typename m_PixelType> typename Bitmap<m_PixelType>::PixelColumnConst Bitmap<m_PixelType>::get_column(SizeT index) const"));
	}

	template <typename m_PixelType>
	SizeT
	Bitmap<m_PixelType>::get_width() const
	{
		return m_width;
	}

	template <typename m_PixelType>
	SizeT
	Bitmap<m_PixelType>::get_height() const
	{
		return m_height;
	}

	template <typename m_PixelType>
	void
	Bitmap<m_PixelType>::release()
	{
		m_pixels.clear();
	}

	template <>
	bool
	Bitmap<PixelGrey>::load_from_file(
		const std::string &filename)
	{
		int width, height, comp;
		stbi_uc *pixels = stbi_load(
			filename.data(),
			&width,
			&height,
			&comp,
			PixelType::get_color_channels());

		if (pixels != nullptr)
		{
			m_width = width;
			m_height = height;

			m_pixels.clear();
			m_pixels.resize(width * height);
			memcpy_s(
				m_pixels.data(),
				m_pixels.size() * sizeof(PixelType),
				pixels,
				width * height * PixelType::get_color_channels());

			stbi_image_free(pixels);

			return true;
		}

		return false;
	}

	template <>
	bool
	Bitmap<PixelGA>::load_from_file(
		const std::string &filename)
	{
		int width, height, comp;
		stbi_uc *pixels = stbi_load(
			filename.data(),
			&width,
			&height,
			&comp,
			PixelType::get_color_channels());

		if (pixels != nullptr)
		{
			m_width = width;
			m_height = height;

			m_pixels.clear();
			m_pixels.resize(width * height);
			memcpy_s(
				m_pixels.data(),
				m_pixels.size() * sizeof(PixelType),
				pixels,
				width * height * PixelType::get_color_channels());

			stbi_image_free(pixels);

			return true;
		}

		return false;
	}

	template <>
	bool
	Bitmap<PixelRGB>::load_from_file(
		const std::string &filename)
	{
		int width, height, comp;
		stbi_uc *pixels = stbi_load(
			filename.data(),
			&width,
			&height,
			&comp,
			PixelType::get_color_channels());

		if (pixels != nullptr)
		{
			m_width = width;
			m_height = height;

			m_pixels.clear();
			m_pixels.resize(width * height);
			memcpy_s(
				m_pixels.data(),
				m_pixels.size() * sizeof(PixelType),
				pixels,
				width * height * PixelType::get_color_channels());

			stbi_image_free(pixels);

			return true;
		}

		return false;
	}

	template <>
	bool
	Bitmap<PixelRGBA>::load_from_file(
		const std::string &filename)
	{
		int width, height, comp;
		stbi_uc *pixels = stbi_load(
			filename.data(),
			&width,
			&height,
			&comp,
			PixelType::get_color_channels());

		if (pixels != nullptr)
		{
			m_width = width;
			m_height = height;

			m_pixels.clear();
			m_pixels.resize(width * height);
			memcpy_s(
				m_pixels.data(),
				m_pixels.size() * sizeof(PixelType),
				pixels,
				width * height * PixelType::get_color_channels());

			stbi_image_free(pixels);

			return true;
		}

		return false;
	}

	template <>
	bool
	Bitmap<PixelGrey>::load_from_memory(
		SizeT width,
		SizeT height,
		void *source)
	{
		if (source == nullptr)
			throw NullPointerException(
				NTL_STRING("bool Bitmap<PixelGrey>::load_from_memory(SizeT width,SizeT height,void *source)"));

		m_width = width;
		m_height = height;

		m_pixels.clear();
		m_pixels.resize(width * height);
		memcpy_s(
			m_pixels.data(),
			m_pixels.size() * sizeof(PixelType),
			source,
			width * height * PixelType::get_color_channels());

		return true;
	}

	template <>
	bool
	Bitmap<PixelGA>::load_from_memory(
		SizeT width,
		SizeT height,
		void *source)
	{
		if (source == nullptr)
			throw NullPointerException(
				NTL_STRING("bool Bitmap<PixelGA>::load_from_memory(SizeT width,SizeT height,void *source)"));

		m_width = width;
		m_height = height;

		m_pixels.clear();
		m_pixels.resize(width * height);
		memcpy_s(
			m_pixels.data(),
			m_pixels.size() * sizeof(PixelType),
			source,
			width * height * PixelType::get_color_channels());

		return true;
	}

	template <>
	bool
	Bitmap<PixelRGB>::load_from_memory(
		SizeT width,
		SizeT height,
		void *source)
	{
		if (source == nullptr)
			throw NullPointerException(
				NTL_STRING("bool Bitmap<PixelRGB>::load_from_memory(SizeT width,SizeT height,void *source)"));

		m_width = width;
		m_height = height;

		m_pixels.clear();
		m_pixels.resize(width * height);
		memcpy_s(
			m_pixels.data(),
			m_pixels.size() * sizeof(PixelType),
			source,
			width * height * PixelType::get_color_channels());

		return true;
	}

	template <>
	bool
	Bitmap<PixelRGBA>::load_from_memory(
		SizeT width,
		SizeT height,
		void *source)
	{
		if (source == nullptr)
			throw NullPointerException(
				NTL_STRING("bool Bitmap<PixelRGBA>::load_from_memory(SizeT width,SizeT height,void *source)"));

		m_width = width;
		m_height = height;

		m_pixels.clear();
		m_pixels.resize(width * height);
		memcpy_s(
			m_pixels.data(),
			m_pixels.size() * sizeof(PixelType),
			source,
			width * height * PixelType::get_color_channels());

		return true;
	}

	template <>
	void
	Bitmap<PixelGrey>::save_as_png(
		const std::string &filename,
		bool need_flip)
	{
		stbi_flip_vertically_on_write(need_flip);

		stbi_write_png(
			filename.data(),
			m_width,
			m_height,
			PixelType::get_color_channels(),
			m_pixels.data(),
			0);
	}

	template <>
	void
	Bitmap<PixelGA>::save_as_png(
		const std::string &filename,
		bool need_flip)
	{
		stbi_flip_vertically_on_write(need_flip);

		stbi_write_png(
			filename.data(),
			m_width,
			m_height,
			PixelType::get_color_channels(),
			m_pixels.data(),
			0);
	}

	template <>
	void
	Bitmap<PixelRGB>::save_as_png(
		const std::string &filename,
		bool need_flip)
	{
		stbi_flip_vertically_on_write(need_flip);

		stbi_write_png(
			filename.data(),
			m_width,
			m_height,
			PixelType::get_color_channels(),
			m_pixels.data(),
			0);
	}

	template <>
	void
	Bitmap<PixelRGBA>::save_as_png(
		const std::string &filename,
		bool need_flip)
	{
		stbi_flip_vertically_on_write(need_flip);

		stbi_write_png(
			filename.data(),
			m_width,
			m_height,
			PixelType::get_color_channels(),
			m_pixels.data(),
			0);
	}

} // namespace ntl

#endif