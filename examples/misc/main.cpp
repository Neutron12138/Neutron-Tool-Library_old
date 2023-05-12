#include <iostream>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

struct MyEnum : public ntl::Enumeration
{
    using EnumType = ntl::Enumeration;

    static const EnumType A;
    static const EnumType B;
    static const EnumType C;
};

const MyEnum::EnumType MyEnum::A = EnumType(0);
const MyEnum::EnumType MyEnum::B = EnumType(1);
const MyEnum::EnumType MyEnum::C = EnumType(2);

struct MyEnum2 : public MyEnum
{
    static const EnumType D;
    static const EnumType E;
    static const EnumType F;
};

const MyEnum2::EnumType MyEnum2::D = EnumType(3);
const MyEnum2::EnumType MyEnum2::E = EnumType(4);
const MyEnum2::EnumType MyEnum2::F = EnumType(5);

namespace MyEnum3
{
    using EnumType = ntl::StringEnumeration;

    static const EnumType A = EnumType("A");
    static const EnumType B = EnumType("B");
    static const EnumType C = EnumType("C");

} // namespace MyEnum3

ntl::Result<int> add(int *a, int *b);

int main()
{
    std::cout << "MyEnum2::A:\t" << MyEnum2::A << std::endl
              << "MyEnum2::B:\t" << MyEnum2::B << std::endl
              << "MyEnum2::C:\t" << MyEnum2::C << std::endl
              << std::endl
              << "MyEnum2::D:\t" << MyEnum2::D << std::endl
              << "MyEnum2::E:\t" << MyEnum2::E << std::endl
              << "MyEnum2::F:\t" << MyEnum2::F << std::endl
              << std::endl
              << "MyEnum3::A:\t" << MyEnum3::A << std::endl
              << "MyEnum3::B:\t" << MyEnum3::B << std::endl
              << "MyEnum3::C:\t" << MyEnum3::C << std::endl;

    std::cout << std::endl;

    ntl::InitializeOnly<int> a(10);
    int b = a;
    // 会报错
    // *a=100;
    std::cout << "a:" << a << std::endl;

    int x = 1, y = 2;
    ntl::Result<int> result = add(nullptr, nullptr);
    ntl::Result<int> result2 = add(&x, &y);
    std::cout << "result.success:" << result.success << std::endl
              << "result.data.has_value():" << result.data.has_value() << std::endl
              << "*result.reason:" << *result.reason << std::endl
              << "result2.success:" << result2.success << std::endl
              << "*result2.data:" << *result2.data << std::endl
              << "*result2.reason.has_value():" << result2.reason.has_value() << std::endl;

    std::cout << std::endl;

    ntl::Variant var = int(10);
    std::cout << int(var) << std::endl;

    var = float(10.0f);
    std::cout << float(var) << std::endl;
    var = std::string("abc");
    std::cout << std::string(var) << std::endl;
    var = std::vector<ntl::Variant>();

    std::cout << "sizeof(ntl::Variant):" << sizeof(ntl::Variant) << std::endl;

    return 0;
}

ntl::Result<int> add(int *a, int *b)
{
    if (a == nullptr || b == nullptr)
        return {"nullptr"};

    return {*a + *b};
}
