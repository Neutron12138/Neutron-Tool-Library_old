#ifndef __NEUTRONTL_MATHS_ANGLE_CPP__
#define __NEUTRONTL_MATHS_ANGLE_CPP__

#include "Angle.hpp"
#include "MathsContants.hpp"

namespace ntl
{
    template <typename m_ValueType>
    Angle<m_ValueType>::Angle(
        float v,
        AngleUnit u)
        : value(v),
          unit(u) {}

    template <typename m_ValueType>
    typename Angle<m_ValueType>::ValueType
    Angle<m_ValueType>::as_radian() const
    {
        switch (unit)
        {
        case AngleUnit::Radian:
            return value;

        case AngleUnit::Degree:
            return as_radian(value);

        default:
            return value;
        }
    }

    template <typename m_ValueType>
    typename Angle<m_ValueType>::ValueType
    Angle<m_ValueType>::as_degree() const
    {
        switch (unit)
        {
        case AngleUnit::Radian:
            return as_degree(value);

        case AngleUnit::Degree:
            return value;

        default:
            return value;
        }
    }

    template <typename m_ValueType>
    typename Angle<m_ValueType>::ValueType
    Angle<m_ValueType>::as_radian(
        const typename Angle<m_ValueType>::ValueType &value)
    {
        return value / static_cast<ValueType>(180.0f) * static_cast<ValueType>(MathsConstants::exact::ePI);
    }

    template <typename m_ValueType>
    typename Angle<m_ValueType>::ValueType
    Angle<m_ValueType>::as_degree(
        const typename Angle<m_ValueType>::ValueType &value)
    {
        return value * static_cast<ValueType>(180.0f) / static_cast<ValueType>(MathsConstants::exact::ePI);
    }

} // namespace ntl

#endif