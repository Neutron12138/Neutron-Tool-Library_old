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
        Time() = default;
        explicit Time(clock_t clocks);
        explicit Time(float seconds);
        Time(const SelfType &from) = default;
        ~Time() override = default;

    public:
        inline SelfType &operator=(const SelfType &from) = default;
        inline bool operator==(const Time &another) const;
        inline bool operator>(const Time &another) const;
        inline bool operator>=(const Time &another) const;
        inline bool operator<(const Time &another) const;
        inline bool operator<=(const Time &another) const;
        inline Time operator+(const Time &another) const;
        inline Time operator-(const Time &another) const;
        inline Time operator*(const Time &another) const;
        inline Time operator/(const Time &another) const;
        inline Time operator%(const Time &another) const;
        inline Time &operator+=(const Time &another);
        inline Time &operator-=(const Time &another);
        inline Time &operator*=(const Time &another);
        inline Time &operator/=(const Time &another);
        inline Time &operator%=(const Time &another);
        inline operator clock_t() const;
        inline operator float() const;

    public:
        /// @brief 转换为clock_t
        /// @return 转换结果
        inline clock_t as_clocks() const;

        /// @brief 转换为毫秒
        /// @return 转换结果
        inline long as_milliseconds() const;

        /// @brief 转换为秒
        /// @return 转换结果
        inline float as_seconds() const;
    };

    /// @brief 获取当前时间
    /// @return 当前时间
    inline Time get_current_time();

} // namespace ntl

#endif