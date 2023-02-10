#include <iostream>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

int main()
{
    ntl::script::MemoryPointer ptr(ntl::script::Types::Integer::TYPE_SIZE);
    ntl::script::Types::Integer integer;

    std::cout << ntl::script::Types::Integer::as_internal_type(ptr) << std::endl;

    integer.construction(ptr);
    std::cout << ntl::script::Types::Integer::as_internal_type(ptr) << std::endl;

    ntl::script::ArgumentsArray args = {ntl::script::Types::Integer::InternalType(666)};
    integer.construction(ptr, args);
    std::cout << ntl::script::Types::Integer::as_internal_type(ptr) << std::endl;

    integer.destruction(ptr);
    std::cout << (void *)ptr.data() << std::endl;

    std::cout << "ntl::script::TypeID::integer:" << ntl::script::TypeID::integer << std::endl;
    std::cout << "ntl::script::TypeID::floating:" << ntl::script::TypeID::floating << std::endl;

    return 0;
}