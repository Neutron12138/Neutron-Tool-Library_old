#include <iostream>
#define NEUTRONTL_ENABLE_DEBUG
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

void test();

int main()
{
    NTL_set_debug_output([](const char *str)
                         { std::cout << str << std::endl; });

    NTL_debug_output("abc");

    std::cout << "----------" << std::endl;

    NTL_debug("int main()", test(););

    std::cout << "----------" << std::endl;

    NTL_debug("int main()", throw 666;);

    return 0;
}

void test()
{
    std::array<int, 0> a;
    NTL_debug_throw("void test()", a.at(0););
}
