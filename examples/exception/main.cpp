#include <iostream>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

void test();

int main()
{
    try
    {
        test();
    }
    catch (const ntl::Exception &e)
    {
        std::cout << e << std::endl;
    }

    return 0;
}

void test()
{
    throw ntl::NullPointerException("some place");
}