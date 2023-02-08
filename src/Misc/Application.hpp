#ifndef __NEUTRONTL_MISC_APPLICATION_HPP__
#define __NEUTRONTL_MISC_APPLICATION_HPP__

#include "../Base/Object.hpp"
#include "../Time/Time.hpp"
#include "../Instances.hpp"

namespace ntl
{
    /// @brief 应用程序类
    class Application : public Object
    {
    public:
        using SelfType = Application;
        using ParentType = Object;

    protected:
        /// @brief 上一次调用onIdle()的时间
        Time m_last_idle = ZeroSecond;

        /// @brief 两次调用onIdle()之间相差的时间
        Time m_delta_time = ZeroSecond;

        /// @brief 是否正在运行
        bool m_is_running = false;

        /// @brief 退出码
        int m_exit_code = EXIT_SUCCESS;

    public:
        constexpr Application() = default;
        constexpr explicit Application(const SelfType &from) = default;
        ~Application() override = default;

    public:
        constexpr SelfType &operator=(const SelfType &from) = default;

    public:
        /// @brief 运行程序
        /// @return 退出码
        virtual int run();

        /// @brief 退出程序
        /// @param code 退出码
        virtual void quit(int code = EXIT_SUCCESS);

    protected:
        /// @brief 当程序创建时调用
        virtual void onCreated() = 0;

        /// @brief 当程序销毁时调用
        virtual void onDestroyed() = 0;

        /// @brief 当系统空闲时调用
        virtual void onIdle() = 0;
    };
} // namespace ntl

#endif