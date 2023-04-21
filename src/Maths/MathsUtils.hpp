#ifndef __NEUTRONTL_MATHS_MATHSUTILS_HPP__
#define __NEUTRONTL_MATHS_MATHSUTILS_HPP__

#include "../Base/Type.hpp"

namespace ntl
{
    /// @brief 取余
    /// @tparam ValueType 值类型
    /// @param dividend 被除数
    /// @param divisor 除数
    /// @return 余数
    template <typename ValueType>
    ValueType get_remainder(const ValueType &dividend,
                            const ValueType &divisor);

    /// @brief 把值截断在[min,max)之间
    /// @tparam ValueType 值类型
    /// @param value 值
    /// @param min 最小值
    /// @param max 最大值
    /// @return 值
    template <typename ValueType>
    ValueType cut_off(const ValueType &value,
                      const ValueType &min,
                      const ValueType &max);

} // namespace ntl

#endif
