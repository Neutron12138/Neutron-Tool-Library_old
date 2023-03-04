#include <iostream>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

int main()
{
    std::cout << "ntl::MathsConstants::PI:" << ntl::MathsConstants::PI << std::endl;
    std::cout << "ntl::MathsConstants::exact::ePI:" << ntl::MathsConstants::exact::ePI << std::endl;

    ntl::Angle<float> a1(ntl::MathsConstants::PI_HALF, ntl::Angle<float>::AngleUnit::Radian);
    ntl::Angle<float> a2(180.0f, ntl::Angle<float>::AngleUnit::Degree);

    std::cout << "a1.as_radian():" << a1.as_radian() << std::endl
              << "a1.as_degree():" << a1.as_degree() << std::endl
              << "a2.as_radian():" << a2.as_radian() << std::endl
              << "a2.as_degree():" << a2.as_degree() << std::endl;

    return 0;
}