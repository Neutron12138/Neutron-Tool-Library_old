#include <iostream>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

int main()
{
    ntl::String str1 = "666";
    std::cout << str1 << std::endl;
    std::wcout << str1 << std::endl;

    ntl::String str2 = L"999";
    std::cout << str2 << std::endl;
    std::wcout << str2 << std::endl;

    ntl::String str3 = str1 + str2;
    std::cout << str3 << std::endl;
    std::wcout << str3 << std::endl;

    ntl::Object obj;
    std::wcout << obj.as_string() << std::endl;

    return 0;
}