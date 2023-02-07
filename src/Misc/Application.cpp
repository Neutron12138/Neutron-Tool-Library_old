#ifndef __NEUTRONTL_MISC_APPLICATION_CPP__
#define __NEUTRONTL_MISC_APPLICATION_CPP__

#include "Application.hpp"

namespace ntl
{
    int Application::run()
    {
        m_is_running = true;
        onCreated();
        m_is_running = false;
        onDestroyed();
        return m_exit_code;
    }

    void Application::quit(int code)
    {
        m_is_running = false;
        m_exit_code = code;
    }
} // namespace ntl

#endif