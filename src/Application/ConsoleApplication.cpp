#ifndef __NEUTRONTL_APPLICATION_CONSOLEAPPLICATION_CPP__
#define __NEUTRONTL_APPLICATION_CONSOLEAPPLICATION_CPP__

#include <windows.h>
#include "ConsoleApplication.hpp"

namespace ntl
{
    bool ConsoleApplication::m_console_window_visibility = true;

    void
    ConsoleApplication::set_console_window_visibility(
        bool visibility)
    {
        m_console_window_visibility = visibility;
        if (m_console_window_visibility)
            ShowWindow(GetConsoleWindow(), SW_SHOW);
        else
            ShowWindow(GetConsoleWindow(), SW_HIDE);
    }

    bool
    ConsoleApplication::is_console_window_visible()
    {
        bool is_visible = (GetWindowLong(
                               GetConsoleWindow(),
                               GWL_STYLE) &
                           WS_VISIBLE) != 0;
        m_console_window_visibility = is_visible;
        return is_visible;
    }
} // namespace ntl

#endif