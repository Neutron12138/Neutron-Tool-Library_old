#include <iostream>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

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

    static ntl::Byte *construct()
    {
        return reinterpret_cast<ntl::Byte *>(new MyClass());
    }

    static void destruct(ntl::Byte *ptr)
    {
        std::cout << "ready to delete" << std::endl;
        delete reinterpret_cast<MyClass *>(ptr);
        std::cout << "succeed to delete" << std::endl;
    }
};

int MyClass::var2 = 0;

__attribute__((constructor)) void prepare()
{
    ntl::reflector.register_class<MyClass>("MyClass");
}

int main()
{
    try
    {
        {
            ntl::NonStaticMethod method(&MyClass::func, 1);
            ntl::NonStaticField field(&MyClass::var);
            ntl::StaticMethod method2(&MyClass::func2, 1);
            ntl::StaticField field2(&MyClass::var2);

            MyClass object;
            field.of<int>(&object) = 666;
            method.call<void>(&object, 999);
            field2.of<int>() = 123;
            method2.call<void>(456);
        }

        std::cout << "----------" << std::endl;

        {
            // ntl::Byte *object2 = ntl::reflector.get_class("MyClass")->get_static_methods().at("<construction>").call<ntl::Byte *>();
            ntl::Byte *object2 = new ntl::Byte[ntl::reflector.get_class("MyClass")->get_size()];
            ntl::reflector.get_class("MyClass")->get_nonstatic_fields().at("var").of<int>(object2) = 1;
            ntl::reflector.get_class("MyClass")->get_nonstatic_methods().at("func(int)").call<void>(object2, 10);
            ntl::reflector.get_class("MyClass")->get_static_fields().at("var2").of<int>() = 100;
            ntl::reflector.get_class("MyClass")->get_static_methods().at("func2(int)").call<void>(1000);
            // ntl::reflector.get_class("MyClass")->get_static_methods().at("<destruction>").call<void>(object2);
            delete[] object2;
        }
    }
    catch (const ntl::Exception &exception)
    {
        std::cout << exception << std::endl;
    }

    return 0;
}