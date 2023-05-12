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
        std::cout << "MyObject(" << m_id << ") constructed" << std::endl;
    }

    ~MyObject()
    {
        std::cout << "MyObject(" << m_id << ") destructed" << std::endl;
    }
};

struct MyDeleter : public ntl::BasicDeleter<MyObject>
{
    void operator()(MyObject *ptr) const override
    {
        std::cout << "MyObject deleted" << std::endl;
        delete ptr;
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
    ntl::SharedPointer<MyObject> ptr1 = ntl::make_shared_and_deleter<MyObject>(MyDeleter(), 1);
    ntl::UniquePointer<MyObject> ptr2 = ntl::make_unique<MyObject>(2);
    ntl::UniquePointer<MyObject, MyDeleter> ptr3 = ntl::make_unique_and_deleter<MyObject, MyDeleter>(MyDeleter(), 3);

    ntl::UniquePointer<MyObject[]> ptr4(new MyObject[2]);
    for (size_t i = 0; i < 2; i++)
    {
        ptr4[i].m_id = i + 4;
    }

    std::cout << "----------" << std::endl;

    std::function<void(void *)> deleter = ntl::BasicDeleter<MyObject>();
    deleter(new MyObject(6));

    std::cout << "----------" << std::endl;

    return 0;
}