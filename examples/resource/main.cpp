#include <iostream>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

class MyRes : public ntl::ResourceObject
{
public:
    MyRes() = default;
    ~MyRes() = default;

public:
    void release()
    {
        std::cout << "released" << std::endl;
    }
};

int main()
{
    ntl::UniquePointer<MyRes, ntl::ResourceDeleter<MyRes>> ptr(new MyRes());
    
    try
    {
        ntl::ResourceDeleter<MyRes>()(nullptr);
    }
    catch (const ntl::NullPointerException &e)
    {
        std::cout << e << std::endl;
    }

    return 0;
}