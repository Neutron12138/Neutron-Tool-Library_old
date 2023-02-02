#ifndef __NEUTRONTL_TIME_TIME_HPP__
#define __NEUTRONTL_TIME_TIME_HPP__

#include <ctime>
#include <future>
#include "../Base/Object.hpp"

namespace ntl
{
    /// @brief 时间类
    class NTL_ALIGN Time : public Object
    {
    public:
        using SelfType = Time;
        using ParentType = Object;

    private:
        /// @brief 时刻数
        clock_t m_clocks = 0;

    public:
        NTL_INLINE Time() = default;
        NTL_INLINE NTL_EXPLICIT Time(clock_t clocks);
        NTL_INLINE NTL_EXPLICIT Time(float seconds);
        NTL_INLINE Time(const SelfType &from) = default;
        NTL_INLINE ~Time() = default;

    public:
        NTL_INLINE SelfType &operator=(const SelfType &from) = default;
        NTL_INLINE bool operator==(const Time &another) const;
        NTL_INLINE bool operator>(const Time &another) const;
        NTL_INLINE bool operator>=(const Time &another) const;
        NTL_INLINE bool operator<(const Time &another) const;
        NTL_INLINE bool operator<=(const Time &another) const;
        NTL_INLINE Time operator+(const Time &another) const;
        NTL_INLINE Time operator-(const Time &another) const;
        NTL_INLINE Time operator*(const Time &another) const;
        NTL_INLINE Time operator/(const Time &another) const;
        NTL_INLINE Time operator%(const Time &another) const;
        NTL_INLINE Time &operator+=(const Time &another);
        NTL_INLINE Time &operator-=(const Time &another);
        NTL_INLINE Time &operator*=(const Time &another);
        NTL_INLINE Time &operator/=(const Time &another);
        NTL_INLINE Time &operator%=(const Time &another);
        NTL_INLINE operator clock_t() const;
        NTL_INLINE operator float() const;

    public:
        /// @brief 转换为clock_t
        /// @return 转换结果
        NTL_INLINE clock_t as_clocks() const;

        /// @brief 转换为毫秒
        /// @return 转换结果
        NTL_INLINE long as_milliseconds() const;

        /// @brief 转换为秒
        /// @return 转换结果
        NTL_INLINE float as_seconds() const;
    };

    /// @brief 获取当前时间
    /// @return 当前时间
    NTL_INLINE Time get_current_time();

} // namespace ntl

#endif