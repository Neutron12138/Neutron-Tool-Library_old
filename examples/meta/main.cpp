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
template <typename Type>
void print();

int main()
{
    std::cout << "ntl::get_type_info(123)" << std::endl;
    print(ntl::get_type_info(123));

    SPLIT_LINE_TRI;

    std::cout << "ntl::NonCopyable[1][2][3]>" << std::endl;
    print<ntl::TypeInfo<ntl::NonCopyable[1][2][3]>>();

    SPLIT_LINE_TRI;

    std::cout << "const ntl::Object &&" << std::endl;
    print<ntl::TypeInfo<const ntl::Object &&>>();

    return 0;
}

template <typename Type>
void print(const ntl::TypeInfo<Type> &info)
{
    std::cout << "sizeof(ntl::TypeInfo<Type>)"
              << ":\t\t\t\t" << sizeof(ntl::TypeInfo<Type>) << std::endl;

    // std::cout << info.type_name << std::endl;

    std::cout << "fundamental_type:\t\t\t\t" << info.fundamental_type << std::endl;
    std::cout << "compound_type:\t\t\t\t" << info.compound_type << std::endl;
    std::cout << "type_attribute:\t\t\t\t" << info.type_attribute << std::endl;
    std::cout << "supported_operations:\t\t\t\t" << info.supported_operations << std::endl;

    std::cout << "ntl::TypeUtils::is_fit<Type>(info.fundamental_type):\t\t\t\t" << ntl::TypeUtils::is_fit<Type>(info.fundamental_type) << std::endl;
    std::cout << "ntl::TypeUtils::is_fit<Type>(info.compound_type):\t\t\t\t" << ntl::TypeUtils::is_fit<Type>(info.compound_type) << std::endl;
    std::cout << "ntl::TypeUtils::is_fit<Type>(info.type_attribute):\t\t\t\t" << ntl::TypeUtils::is_fit<Type>(info.type_attribute) << std::endl;
    std::cout << "ntl::TypeUtils::is_fit<Type>(info.supported_operations):\t\t\t\t" << ntl::TypeUtils::is_fit<Type>(info.supported_operations) << std::endl;

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

    SPLIT_LINE;

    PRINT(const);
    PRINT(volatile);
    PRINT(trivial);
    PRINT(trivially_copyable);
    PRINT(standard_layout);
    std::cout << "has_unique_object_representations"
              << ":\t\t\t\t" << (info.has_unique_object_representations ? "true" : "false") << std::endl;
    // std::cout << "has_strong_structural_equality"
    //           << ":\t\t\t\t" << (info.has_strong_structural_equality ? "true" : "false") << std::endl PRINT(empty);
    PRINT(polymorphic);
    PRINT(abstract);
    PRINT(final);
    PRINT(aggregate);
    PRINT(signed);
    PRINT(unsigned);
    // PRINT(bounded_array);
    // PRINT(unbounded_array);
    // PRINT(scoped_enum);

    SPLIT_LINE;

    PRINT(constructible);
    PRINT(trivially_constructible);
    PRINT(nothrow_constructible);
    PRINT(default_constructible);
    PRINT(trivially_default_constructible);
    PRINT(nothrow_default_constructible);
    PRINT(copy_constructible);
    PRINT(trivially_copy_constructible);
    PRINT(nothrow_copy_constructible);
    PRINT(move_constructible);
    PRINT(trivially_move_constructible);
    PRINT(nothrow_move_constructible);
    PRINT(copy_assignable);
    PRINT(trivially_copy_assignable);
    PRINT(nothrow_copy_assignable);
    PRINT(move_assignable);
    PRINT(trivially_move_assignable);
    PRINT(nothrow_move_assignable);
    PRINT(destructible);
    PRINT(trivially_destructible);
    PRINT(nothrow_destructible);
    std::cout << "has_virtual_destructor:\t\t\t\t" << (info.has_virtual_destructor ? "true" : "false") << std::endl;
    PRINT(swappable);
    PRINT(nothrow_swappable);

    SPLIT_LINE;

    std::cout << "alignment_of:\t\t\t\t" << info.alignment_of << std::endl;
    std::cout << "rank:\t\t\t\t" << info.rank << std::endl;
}

template <typename Type>
void print()
{
    print(ntl::TypeInfo<Type>());
}
