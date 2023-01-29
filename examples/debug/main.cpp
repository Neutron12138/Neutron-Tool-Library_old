#include <iostream>
#define NEUTRONTL_ENABLE_DEBUG
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

int main()
{
    NTL_set_debug_output([](const wchar_t *str)
                         { std::wcout << str << std::endl; });
    NTL_debug_output(L"abc");
    return 0;
}