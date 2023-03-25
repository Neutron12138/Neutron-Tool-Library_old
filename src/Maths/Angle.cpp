#ifndef __NEUTRONTL_MATHS_ANGLE_CPP__
#define __NEUTRONTL_MATHS_ANGLE_CPP__

#include "Angle.hpp"
#include "MathsContants.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    template <typename m_ValueType>
    Angle<m_ValueType>::Angle(
        float v,
        AngleUnit u)
        : value(v),
          unit(u) {}

    template <typename m_ValueType>
    bool
    Angle<m_ValueType>::operator==(
        const typename Angle<m_ValueType>::SelfType &another) const
    {
        return value == as_same_unit(another).value;
    }

    template <typename m_ValueType>
    bool
    Angle<m_ValueType>::operator!=(
        const typename Angle<m_ValueType>::SelfType &another) const
    {
        return !operator==(another);
    }

    template <typename m_ValueType>
    typename Angle<m_ValueType>::SelfType
    Angle<m_ValueType>::operator+(
        const typename Angle<m_ValueType>::SelfType &another) const
    {
        return Angle<m_ValueType>::SelfType(
            value + as_same_unit(another).value,
            unit);
    }

    template <typename m_ValueType>
    typename Angle<m_ValueType>::SelfType
    Angle<m_ValueType>::operator-(
        const typename Angle<m_ValueType>::SelfType &another) const
    {
        return Angle<m_ValueType>::SelfType(
            value - as_same_unit(another).value,
            unit);
    }

    template <typename m_ValueType>
    typename Angle<m_ValueType>::SelfType
    Angle<m_ValueType>::operator*(
        const typename Angle<m_ValueType>::ValueType &another) const
    {
        return Angle<m_ValueType>::SelfType(
            value * another,
            unit);
    }

    template <typename m_ValueType>
    typename Angle<m_ValueType>::SelfType
    Angle<m_ValueType>::operator/(
        const typename Angle<m_ValueType>::ValueType &another) const
    {
        return Angle<m_ValueType>::SelfType(
            value / another,
            unit);
    }

    template <typename m_ValueType>
    typename Angle<m_ValueType>::SelfType &
    Angle<m_ValueType>::operator+=(
        const typename Angle<m_ValueType>::SelfType &another)
    {
        value = operator+(another);
        return *this;
    }

    template <typename m_ValueType>
    typename Angle<m_ValueType>::SelfType &
    Angle<m_ValueType>::operator-=(
        const typename Angle<m_ValueType>::SelfType &another)
    {
        value = operator-(another);
        return *this;
    }

    template <typename m_ValueType>
    typename Angle<m_ValueType>::SelfType &
    Angle<m_ValueType>::operator*=(
        const typename Angle<m_ValueType>::ValueType &another)
    {
        value = operator*(another);
        return *this;
    }

    template <typename m_ValueType>
    typename Angle<m_ValueType>::SelfType &
    Angle<m_ValueType>::operator/=(
        const typename Angle<m_ValueType>::ValueType &another)
    {
        value = operator/(another);
        return *this;
    }

    template <typename m_ValueType>
    Angle<m_ValueType>::operator typename Angle<m_ValueType>::ValueType() const
    {
        return value;
    }

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
    typename Angle<m_ValueType>::SelfType
    Angle<m_ValueType>::as_same_unit(
        const typename Angle<m_ValueType>::SelfType &another) const
    {
        using AngleType = typename Angle<m_ValueType>::SelfType;

        switch (unit)
        {
        case AngleUnit::Radian:
            return AngleType(
                as_radian(another.value),
                AngleUnit::Radian);
            break;

        case AngleUnit::Degree:
            return AngleType(
                as_degree(another.value),
                AngleUnit::Degree);
            break;

        default:
            return AngleType(another);
            break;
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

    template <typename ValueType>
    OutputStream &
    operator<<(
        OutputStream &os,
        const Angle<ValueType> &angle)
    {
        using AngleType = Angle<ValueType>;

        os << StringUtils::to_string(angle.value);
        switch (angle.unit)
        {
        case AngleType::AngleUnit::Radian:
            os << "rad";
            break;

        case AngleType::AngleUnit::Degree:
            os << "deg";
            break;

        default:
            break;
        }
        return os;
    }

} // namespace ntl

#endif