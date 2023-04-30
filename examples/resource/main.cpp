#include <iostream>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

struct MyRes : public ntl::ResourceObject
{
    ~MyRes()
    {
        std::cout << "resource destructed" << std::endl;
    }

    void release() override
    {
        std::cout << "resource released" << std::endl;
    }
};

int main()
{
    ntl::SharedPointer<MyRes> res =
        ntl::make_shared_and_deleter<MyRes>(ntl::ResourceDeleter<MyRes>());

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
