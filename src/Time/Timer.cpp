#ifndef __NEUTRONTL_TIME_TIMER_CPP__
#define __NEUTRONTL_TIME_TIMER_CPP__

#include "Timer.hpp"

namespace ntl
{
    Timer::SelfType &Timer::start()
    {
        // 如果计时尚未开始
        if (!m_is_started)
        {
            m_is_started = true;
            m_starting_time = get_current_time();
        }
        return *this;
    }

    Timer::SelfType &Timer::stop()
    {
        // 如果计时已经开始
        if (m_is_started)
        {
            m_is_started = false;
            const Time current_time = get_current_time();

            // 计算经过的时间
            m_during_time = current_time - m_starting_time;
            // 增加总时长
            m_total_time += m_during_time;
        }
        return *this;
    }

    Timer::SelfType &Timer::reset()
    {
        m_total_time = ZeroSecond;
        m_starting_time = ZeroSecond;
        m_is_started = false;
        m_during_time = ZeroSecond;
        return *this;
    }

    Time Timer::get_total_time()
    {
        return m_total_time;
    }

    Time Timer::get_starting_time()
    {
        return m_starting_time;
    }

    bool Timer::is_started()
    {
        return m_is_started;
    }

    Time Timer::get_during_time()
    {
        return m_during_time;
    }

} // namespace ntl

#endif