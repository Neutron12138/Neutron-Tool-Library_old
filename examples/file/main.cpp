#include <iostream>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

int main()
{
    auto vec = ntl::read_all_from_file("1.txt");
    vec.push_back(0);

    std::cout << vec.data() << std::endl;
    std::cout << ntl::read_from_file<ntl::String>("1.txt") << std::endl;

    return 0;
}
