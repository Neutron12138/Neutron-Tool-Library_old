#include <iostream>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

#define PRINT(type) std::cout << #type << ":\t\t\t\t" << (info.is_##type ? "true" : "false") << std::endl

#define SPLIT_LINE std::cout << "--------------------" << std::endl \
                             << std::endl

#define SPLIT_LINE_TRI std::cout << "--------------------" << std::endl \
                                 << "--------------------" << std::endl \
                                 << "--------------------" << std::endl \
                                 << std::endl                           \
                                 << std::endl                           \
                                 << std::endl

template <typename Type>
void print(const ntl::TypeInfo<Type> &info);

int main()
{
    std::cout << "ntl::get_type_info(123)" << std::endl;
    print(ntl::get_type_info(123));

    SPLIT_LINE_TRI;

    std::cout << "ntl::get_type_info(666.0f)" << std::endl;
    print(ntl::get_type_info(666.0f));

    SPLIT_LINE_TRI;

    std::cout << "ntl::get_type_info(ntl::Object())" << std::endl;
    print(ntl::get_type_info(ntl::Object()));

    return 0;
}

template <typename Type>
void print(const ntl::TypeInfo<Type> &info)
{
    std::cout << "sizeof(ntl::TypeInfo<int>)"
              << ":\t\t\t\t" << sizeof(ntl::TypeInfo<int>) << std::endl;

    std::cout << info.type_name << std::endl;

    SPLIT_LINE;

    PRINT(void);
    PRINT(null_pointer);
    PRINT(integral);
    PRINT(floating_point);
    PRINT(array);
    PRINT(enum);
    PRINT(union);
    PRINT(class);
    PRINT(function);
    PRINT(pointer);
    PRINT(lvalue_reference);
    PRINT(rvalue_reference);
    PRINT(member_object_pointer);
    PRINT(member_function_pointer);

    SPLIT_LINE;

    PRINT(fundamental);
    PRINT(arithmetic);
    PRINT(scalar);
    PRINT(object);
    PRINT(compound);
    PRINT(reference);
    PRINT(member_pointer);
}