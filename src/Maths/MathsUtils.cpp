#ifndef __NEUTRONTL_MATHS_MATHSUTILS_CPP__
#define __NEUTRONTL_MATHS_MATHSUTILS_CPP__

#include "MathsUtils.hpp"

namespace ntl
{
    template <typename ValueType>
    ValueType
    get_remainder(
        const ValueType &dividend,
        const ValueType &divisor)
    {
        // 浮点数的商（quotient）
        Float64 q =
            static_cast<Float64>(dividend) /
            static_cast<Float64>(divisor);

        // 整数的商
        Int64 qi = static_cast<Int64>(q);

        // 商的小数（decimal）
        Float64 d = q - static_cast<Float64>(qi);

        // 乘积（product）
        Float64 p =
            static_cast<Float64>(qi) *
            static_cast<Float64>(divisor);

        // 余数（remainder）
        Float64 r = static_cast<Float64>(dividend) - p;

        return static_cast<ValueType>(r);
    }

    template <typename ValueType>
    ValueType
    cut_off(
        const ValueType &value,
        const ValueType &min,
        const ValueType &max)
    {
        ValueType result = value;

        if (result < 0)
        {
            result = get_remainder(result, max);
            result += max;
        }

        if (result >= max)
        {
            result = get_remainder(result, max);
        }

        return static_cast<ValueType>(result);
    }

} // namespace ntl

#endif
