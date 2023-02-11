#ifndef __NEUTRONTL_MISC_MAIN_CPP__
#define __NEUTRONTL_MISC_MAIN_CPP__

#ifdef NEUTRONTL_CONFIG_USE_APPLICATION

#include "Application.hpp"

extern ntl::Application &get_application();

int main(int argc, char *argv[])
{
    return get_application().run(argc, argv);
}

#endif

#endif