#include <iostream>
#define NEUTRONTL_CONFIG_USE_CPP20
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

int main()
{
    std::cout << "std::string():"
              << ntl::cpp20::can_construct<std::string> << std::endl
              << "std::string(const char *):"
              << ntl::cpp20::can_construct<std::string, const char *> << std::endl
              << "std::string(int):"
              << ntl::cpp20::can_construct<std::string, int> << std::endl;

    return 0;
}
