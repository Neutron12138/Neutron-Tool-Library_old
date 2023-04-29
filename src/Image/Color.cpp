#ifndef __NEUTRONTL_IMAGE_COLOR_CPP__
#define __NEUTRONTL_IMAGE_COLOR_CPP__

#include "Color.hpp"
#include "../Exception/OutOfRangeException.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    Color::Color(
        float grey)
        : red(grey),
          green(grey),
          blue(grey) {}

    Color::Color(
        float r,
        float g,
        float b,
        float a)
        : red(r),
          green(g),
          blue(b),
          alpha(a) {}

    float &
    Color::operator[](
        SizeT index)
    {
        switch (index)
        {
        case 0:
            return red;

        case 1:
            return green;

        case 2:
            return blue;

        case 3:
            return alpha;

        default:
            throw OutOfRangeException(
                StringUtils::to_string(
                    NTL_STRING("index: "),
                    index,
                    NTL_STRING(", total: "),
                    4),
                NTL_MAKE_STATEMENT_INFO("float &Color::operator[](SizeT index)"));
        }
    }

    const float &
    Color::operator[](
        SizeT index) const
    {
        switch (index)
        {
        case 0:
            return red;

        case 1:
            return green;

        case 2:
            return blue;

        case 3:
            return alpha;

        default:
            throw OutOfRangeException(
                StringUtils::to_string(
                    NTL_STRING("index: "),
                    index,
                    NTL_STRING(", total: "),
                    4),
                NTL_MAKE_STATEMENT_INFO("const float &Color::operator[](SizeT index) const"));
        }
    }

} // namespace ntl

#endif