#include <iostream>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

class MyObject
{
public:
    int m_id = -1;

public:
    MyObject()
    {
        std::cout << "MyObject array constructing" << std::endl;
    }

    MyObject(int id) : m_id(id)
    {
        std::cout << "MyObject " << m_id << " constructed" << std::endl;
    }

    ~MyObject()
    {
        std::cout << "MyObject " << m_id << " destructed" << std::endl;
    }
};

int main()
{
    try
    {
        ntl::BasicDeleter<MyObject>()(nullptr);
    }
    catch (const ntl::NullPointerException &e)
    {
        std::cout << e << std::endl;
    }

    std::cout << "----------" << std::endl;

    ntl::SharedPointer<MyObject> ptr0 = ntl::make_shared<MyObject>(0);
    ntl::UniquePointer<MyObject> ptr1 = ntl::make_unique<MyObject>(1);

    ntl::UniquePointer<MyObject[]> ptr2(new MyObject[2]);
    for (size_t i = 0; i < 2; i++)
    {
        ptr2[i].m_id = i + 2;
    }

    std::cout << "----------" << std::endl;

    return 0;
}