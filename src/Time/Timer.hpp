#ifndef __NEUTRONTL_TIME_TIMER_HPP__
#define __NEUTRONTL_TIME_TIMER_HPP__

#include "../Base/Object.hpp"
#include "Time.hpp"
#include "../Instances.hpp"

namespace ntl
{
    /// @brief 计时器类
    class Timer : public Object
    {
    public:
        using SelfType = Timer;
        using ParentType = Object;

    private:
        /// @brief 时间总计
        Time m_total_time = ZeroSecond;

        /// @brief 计时开始时间
        Time m_starting_time = ZeroSecond;

        /// @brief 是否正在计时
        bool m_is_started = false;

        /// @brief 上一次计时了多久
        Time m_during_time = ZeroSecond;

    public:
        Timer() = default;
        Timer(const SelfType &from) = default;
        ~Timer() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        /// @brief 开始计时
        /// @return 本对象
        SelfType &start();

        /// @brief 停止计时
        /// @return 自开始时经过了多久
        SelfType &stop();

        /// @brief 重置计时器
        /// @return 本对象
        SelfType &reset();

        /// @brief 获取时间总计
        /// @return 时间总计
        Time get_total_time();

        /// @brief 获取计时的起始时间
        /// @return 计时的起始时间
        Time get_starting_time();

        /// @brief 是否正在计时
        /// @return 是否正在计时
        bool is_started();

        /// @brief 获取上次计时了多久
        /// @return 上次计时的时长
        Time get_during_time();
    };

} // namespace ntl

#endif