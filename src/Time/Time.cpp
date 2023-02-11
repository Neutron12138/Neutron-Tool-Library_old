#ifndef __NEUTRONTL_TIME_TIME_CPP__
#define __NEUTRONTL_TIME_TIME_CPP__

#include "Time.hpp"

namespace ntl
{
    inline Time::Time(
        clock_t clocks)
        : m_clocks(clocks) {}

    inline Time::Time(
        float seconds)
    {
        m_clocks = static_cast<clock_t>(seconds * static_cast<float>(CLOCKS_PER_SEC));
    }

    inline bool
    Time::operator==(
        const Time &another) const
    {
        return m_clocks == another.m_clocks;
    }

    inline bool
    Time::operator>(
        const Time &another) const
    {
        return m_clocks > another.m_clocks;
    }

    inline bool
    Time::operator>=(
        const Time &another) const
    {
        return (*this == another) || (*this > another);
    }

    inline bool
    Time::operator<(
        const Time &another) const
    {
        return m_clocks < another.m_clocks;
    }

    inline bool
    Time::operator<=(
        const Time &another) const
    {
        return (*this == another) || (*this < another);
    }

    inline Time
    Time::operator+(
        const Time &another) const
    {
        return Time(m_clocks + another.m_clocks);
    }

    inline Time
    Time::operator-(
        const Time &another) const
    {
        return Time(m_clocks - another.m_clocks);
    }

    inline Time
    Time::operator*(
        const Time &another) const
    {
        return Time(m_clocks * another.m_clocks);
    }

    inline Time
    Time::operator/(
        const Time &another) const
    {
        return Time(m_clocks / another.m_clocks);
    }

    inline Time
    Time::operator%(
        const Time &another) const
    {
        return Time(m_clocks % another.m_clocks);
    }

    inline Time &
    Time::operator+=(
        const Time &another)
    {
        *this = *this + another;
        return *this;
    }

    inline Time &
    Time::operator-=(
        const Time &another)
    {
        *this = *this - another;
        return *this;
    }

    inline Time &
    Time::operator*=(
        const Time &another)
    {
        *this = *this * another;
        return *this;
    }

    inline Time &
    Time::operator/=(
        const Time &another)
    {
        *this = *this / another;
        return *this;
    }

    inline Time &
    Time::operator%=(
        const Time &another)
    {
        *this = *this % another;
        return *this;
    }

    inline Time::operator clock_t() const
    {
        return as_clocks();
    }

    inline Time::operator float() const
    {
        return as_seconds();
    }

    inline clock_t
    Time::as_clocks() const
    {
        return m_clocks;
    }

    inline long
    Time::as_milliseconds() const
    {
        return static_cast<long>(static_cast<float>(m_clocks) / static_cast<float>(CLOCKS_PER_SEC) * 1000.0f);
    }

    inline float
    Time::as_seconds() const
    {
        return static_cast<float>(m_clocks) / static_cast<float>(CLOCKS_PER_SEC);
    }

    inline Time
    get_current_time()
    {
        return Time(clock());
    }

} // namespace ntl

#endif