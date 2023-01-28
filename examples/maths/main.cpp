#include <iostream>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

int main()
{
    std::cout << ntl::MathsConstants::PI << std::endl;
    std::cout << ntl::MathsConstants::exact::ePI << std::endl;
    return 0;
}