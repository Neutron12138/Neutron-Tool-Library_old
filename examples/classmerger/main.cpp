#include <iostream>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

int main()
{
    ntl::ClassMerger<std::string> str = "abc";
    std::cout << str << std::endl;

    ntl::ClassMerger<std::string> str2;
    str2.as() = "123";
    std::cout << str2.as() << std::endl;

    return 0;
}