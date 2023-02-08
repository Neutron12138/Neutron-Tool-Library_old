#include <iostream>
#define NEUTRONTL_ENABLE_DEBUG
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

int main()
{
    NTL_set_debug_output([](const char *str)
                         { std::cout << str << std::endl; });
    NTL_debug_output("abc");
    return 0;
}