#ifndef __NEUTRONTL_APPLICATION_CONSOLEAPPLICATION_HPP__
#define __NEUTRONTL_APPLICATION_CONSOLEAPPLICATION_HPP__

#include "Application.hpp"

namespace ntl
{
    /// @brief 控制台程序
    class ConsoleApplication : public Application
    {
    public:
        using SelfType = ConsoleApplication;
        using ParentType = Application;

    protected:
        /// @brief 控制台窗口可见性
        static bool m_console_window_visibility;

    public:
        ConsoleApplication() = default;
        explicit ConsoleApplication(const SelfType &from) = default;
        ~ConsoleApplication() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        /// @brief 设置控制台窗口可见性
        /// @param visibility 控制台窗口是否可见
        static void set_console_window_visibility(bool visibility);

        /// @brief 获取控制台窗口是否可见
        /// @return 控制台窗口是否可见
        static bool is_console_window_visible();
    };

} // namespace ntl

#endif