#include <iostream>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

class MyEnum : public ntl::Enumeration
{
public:
    using EnumerationType = ntl::Enumeration;

public:
    static EnumerationType A;
    static EnumerationType B;
    static EnumerationType C;
};

MyEnum::EnumerationType MyEnum::A = EnumerationType(0);
MyEnum::EnumerationType MyEnum::B = EnumerationType(1);
MyEnum::EnumerationType MyEnum::C = EnumerationType(2);

class MyEnum2 : public MyEnum
{
public:
    static EnumerationType D;
    static EnumerationType E;
    static EnumerationType F;
};

MyEnum2::EnumerationType MyEnum2::D = EnumerationType(3);
MyEnum2::EnumerationType MyEnum2::E = EnumerationType(4);
MyEnum2::EnumerationType MyEnum2::F = EnumerationType(5);

int main()
{
    std::cout << "MyEnum2::A:\t" << MyEnum2::A << std::endl
              << "MyEnum2::B:\t" << MyEnum2::B << std::endl
              << "MyEnum2::C:\t" << MyEnum2::C << std::endl
              << "MyEnum2::D:\t" << MyEnum2::D << std::endl
              << "MyEnum2::E:\t" << MyEnum2::E << std::endl
              << "MyEnum2::F:\t" << MyEnum2::F << std::endl;

    return 0;
}