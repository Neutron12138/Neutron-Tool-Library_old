#ifndef __NEUTRONTL_MISC_APPLICATION_CPP__
#define __NEUTRONTL_MISC_APPLICATION_CPP__

#include "Application.hpp"

namespace ntl
{
    int Application::run()
    {
        m_is_running = true;
        onCreated();

        onIdle();

        m_is_running = false;
        onDestroyed();

        return m_exit_code;
    }

    int Application::run(const std::vector<std::string> &args)
    {
        return run();
    }

    int Application::run(int argc, char *argv[])
    {
        std::vector<std::string> args;

        if (argc > 0 && argv != nullptr)
            for (SizeT i = 0; i < argc; i++)
                args.push_back(argv[i]);

        return run(args);
    }

    void Application::quit(int code)
    {
        m_is_running = false;
        m_exit_code = code;
    }
} // namespace ntl

#endif