#include <iostream>
#define NEUTRONTL_CONFIG_USE_CPP20
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

struct A
{
    A copy() { return A(); }
    A &swap(const A &) { return *this; }
};

template <ntl::cpp20::CopyableType T>
void func() {}

int main()
{
    std::cout << "std::string():"
              << ntl::cpp20::can_construct<std::string> << std::endl
              << "std::string(const char *):"
              << ntl::cpp20::can_construct<std::string, const char *> << std::endl
              << "std::string(int):"
              << ntl::cpp20::can_construct<std::string, int> << std::endl;

    std::cout << "----------" << std::endl;

    std::cout << "ntl::cpp20::CopyableType<A>:"
              << ntl::cpp20::CopyableType<A> << std::endl
              << "ntl::cpp20::CopyableType<int>:"
              << ntl::cpp20::CopyableType<int> << std::endl;

    func<A>();
    // func<int>(); 编译失败

    return 0;
}
