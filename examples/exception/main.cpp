#include <iostream>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

void throw_an_exception();
void catch_and_throw_it();
void catch_and_throw_it_again();
void catch_and_throw_it_again_2();

#define TRY(s)                               \
    try                                      \
    {                                        \
        s;                                   \
    }                                        \
    catch (const ntl::Exception &exception)  \
    {                                        \
        std::cout << exception << std::endl; \
    }

int main()
{
    try
    {
        catch_and_throw_it_again_2();
    }
    catch (const ntl::CaughtException &exception)
    {
        std::cout << exception << std::endl;
        std::cout << "NTL_STATEMENT_INFO:" << NTL_STATEMENT_INFO << std::endl;
    }

    std::cout << "----------" << std::endl;

    ntl::Matrix<float, 2, 2> a;
    TRY(a[10]);
    ntl::SharedPointer<int> b;
    TRY(*b);
    ntl::DefaultNode node;
    TRY(node.get_child_node(""));

    return 0;
}

void throw_an_exception()
{
    throw ntl::Exception("exception",
                         "an exception needs to be thrown",
                         NTL_MAKE_STATEMENT_INFO("void throw_an_exception()"));
}

void catch_and_throw_it()
{
    try
    {
        throw_an_exception();
    }
    catch (const ntl::Exception &exception)
    {
        throw ntl::CaughtException(exception, "catch_and_throw_it()");
    }
}

void catch_and_throw_it_again()
{
    try
    {
        catch_and_throw_it();
    }
    catch (const ntl::CaughtException &exception)
    {
        throw ntl::CaughtException(exception, "catch_and_throw_it_again()");
    }
}

void catch_and_throw_it_again_2()
{
    try
    {
        catch_and_throw_it_again();
    }
    catch (const ntl::CaughtException &exception)
    {
        throw ntl::CaughtException(exception, "catch_and_throw_it_again_2()");
    }
}