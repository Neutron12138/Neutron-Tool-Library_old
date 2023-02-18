#include <iostream>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

void throw_an_exception();
void catch_and_throw_it();
void catch_and_throw_it_again();
void catch_and_throw_it_again_2();

int main()
{
    try
    {
        catch_and_throw_it_again_2();
    }
    catch (const ntl::CaughtException &exception)
    {
        std::cout << exception << std::endl;
    }

    return 0;
}

void throw_an_exception()
{
    throw ntl::Exception("exception", "an exception needs to be thrown", "throw_an_exception()");
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