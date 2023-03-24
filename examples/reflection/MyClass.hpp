#ifndef MYCLASS
#define MYCLASS

#include "../../src/NTL.hpp"

class MyClass : public ntl::Reflectible
{
public:
    MyClass()
    {
        std::cout << "MyClass()" << std::endl;
    }

    ~MyClass()
    {
        std::cout << "~MyClass()" << std::endl;
    }

public:
    int var;

    void func(int num)
    {
        std::cout << "The function \"func\" was called successfully, with parameter: " << num << std::endl;
        std::cout << "var = " << var << std::endl;
    }

    static int var2;

    static void func2(int num)
    {
        std::cout << "The function \"func2\" was called successfully, with parameter: " << num << std::endl;
        std::cout << "var2 = " << var2 << std::endl;
    }

public:
    static ntl::Details get_reflection_details()
    {
        ntl::Details::NonStaticFieldMap nonstatic_fields;

        nonstatic_fields.insert(
            ntl::Details::NonStaticFieldMap::value_type(
                "var",
                ntl::NonStaticField(&MyClass::var)));

        ntl::Details::StaticFieldMap static_fields;

        static_fields.insert(
            ntl::Details::StaticFieldMap::value_type(
                "var2",
                ntl::StaticField(&MyClass::var2)));

        ntl::Details::NonStaticMethodMap nonstatic_methods;

        nonstatic_methods.insert(
            ntl::Details::NonStaticMethodMap::value_type(
                "func(int)",
                ntl::NonStaticMethod(&MyClass::func, 1)));

        ntl::Details::StaticMethodMap static_methods;

        static_methods.insert(
            ntl::Details::StaticMethodMap::value_type(
                ntl::Details::get_reflection_details_name,
                ntl::StaticMethod(&MyClass::get_reflection_details, 0)));
        static_methods.insert(
            ntl::Details::StaticMethodMap::value_type(
                ntl::Details::construction_name,
                ntl::StaticMethod(&MyClass::construct, 0)));
        static_methods.insert(
            ntl::Details::StaticMethodMap::value_type(
                ntl::Details::destruction_name,
                ntl::StaticMethod(&MyClass::destruct, 1)));
        static_methods.insert(
            ntl::Details::StaticMethodMap::value_type(
                "func2(int)",
                ntl::StaticMethod(&MyClass::func2, 1)));

        return ntl::Details(
            sizeof(MyClass),
            nonstatic_fields,
            static_fields,
            nonstatic_methods,
            static_methods);
    }

    static ntl::BasicObject *construct()
    {
        return reinterpret_cast<ntl::BasicObject *>(new MyClass());
    }

    static void destruct(ntl::BasicObject *ptr)
    {
        std::cout << "ready to delete" << std::endl;
        delete reinterpret_cast<MyClass *>(ptr);
        std::cout << "succeed to delete" << std::endl;
    }
};

int MyClass::var2 = 0;

#endif
