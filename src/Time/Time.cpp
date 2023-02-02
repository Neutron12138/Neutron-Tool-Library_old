#ifndef __NEUTRONTL_TIME_TIME_CPP__
#define __NEUTRONTL_TIME_TIME_CPP__

#include "Time.hpp"

namespace ntl
{
    NTL_INLINE Time::Time(
        clock_t clocks)
        : m_clocks(clocks) {}

    NTL_INLINE Time::Time(
        float seconds)
    {
        m_clocks = static_cast<clock_t>(seconds * static_cast<float>(CLOCKS_PER_SEC));
    }

    NTL_INLINE bool
    Time::operator==(
        const Time &another) const
    {
        return m_clocks == another.m_clocks;
    }

    NTL_INLINE bool
    Time::operator>(
        const Time &another) const
    {
        return m_clocks > another.m_clocks;
    }

    NTL_INLINE bool
    Time::operator>=(
        const Time &another) const
    {
        return (*this == another) || (*this > another);
    }

    NTL_INLINE bool
    Time::operator<(
        const Time &another) const
    {
        return m_clocks < another.m_clocks;
    }

    NTL_INLINE bool
    Time::operator<=(
        const Time &another) const
    {
        return (*this == another) || (*this < another);
    }

    NTL_INLINE Time
    Time::operator+(
        const Time &another) const
    {
        return Time(m_clocks + another.m_clocks);
    }

    NTL_INLINE Time
    Time::operator-(
        const Time &another) const
    {
        return Time(m_clocks - another.m_clocks);
    }

    NTL_INLINE Time
    Time::operator*(
        const Time &another) const
    {
        return Time(m_clocks * another.m_clocks);
    }

    NTL_INLINE Time
    Time::operator/(
        const Time &another) const
    {
        return Time(m_clocks / another.m_clocks);
    }

    NTL_INLINE Time
    Time::operator%(
        const Time &another) const
    {
        return Time(m_clocks % another.m_clocks);
    }

    NTL_INLINE Time &
    Time::operator+=(
        const Time &another)
    {
        *this = *this + another;
        return *this;
    }

    NTL_INLINE Time &
    Time::operator-=(
        const Time &another)
    {
        *this = *this - another;
        return *this;
    }

    NTL_INLINE Time &
    Time::operator*=(
        const Time &another)
    {
        *this = *this * another;
        return *this;
    }

    NTL_INLINE Time &
    Time::operator/=(
        const Time &another)
    {
        *this = *this / another;
        return *this;
    }

    NTL_INLINE Time &
    Time::operator%=(
        const Time &another)
    {
        *this = *this % another;
        return *this;
    }

    NTL_INLINE Time::operator clock_t() const
    {
        return as_clocks();
    }

    NTL_INLINE Time::operator float() const
    {
        return as_seconds();
    }

    NTL_INLINE clock_t
    Time::as_clocks() const
    {
        return m_clocks;
    }

    NTL_INLINE long
    Time::as_milliseconds() const
    {
        return static_cast<long>(static_cast<float>(m_clocks) / static_cast<float>(CLOCKS_PER_SEC) * 1000.0f);
    }

    NTL_INLINE float
    Time::as_seconds() const
    {
        return static_cast<float>(m_clocks) / static_cast<float>(CLOCKS_PER_SEC);
    }

    NTL_INLINE Time
    get_current_time()
    {
        return Time(clock());
    }

} // namespace ntl

#endif