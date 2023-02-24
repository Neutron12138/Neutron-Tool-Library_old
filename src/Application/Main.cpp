#ifndef __NEUTRONTL_APPLICATION_MAIN_CPP__
#define __NEUTRONTL_APPLICATION_MAIN_CPP__

#ifdef NEUTRONTL_CONFIG_USE_APPLICATION

#include "Application.hpp"

/// @brief 获取应用程序实例
/// @return 应用程序实例，建议返回静态实例
extern ntl::Application &get_application();

int main(int argc, char *argv[])
{
    return get_application().run(argc, argv);
}

#endif

#endif