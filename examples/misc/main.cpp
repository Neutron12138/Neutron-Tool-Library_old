#include <iostream>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

class MyEnum : public ntl::Enumeration
{
public:
    using EnumType = ntl::Enumeration;

public:
    static const EnumType A;
    static const EnumType B;
    static const EnumType C;
};

const MyEnum::EnumType MyEnum::A = EnumType(0);
const MyEnum::EnumType MyEnum::B = EnumType(1);
const MyEnum::EnumType MyEnum::C = EnumType(2);

class MyEnum2 : public MyEnum
{
public:
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

    return 0;
}
