#include <iostream>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

int main()
{
    std::vector<ntl::String> vec = {"a", "b", "c"};
    std::cout << ntl::StringUtils::joint_string(vec.cbegin(), vec.cend()) << std::endl;

    std::cout << "----------" << std::endl;

    ntl::String data("a,b,c,d,e");
    ntl::Regex reg("(.*),(.*)");
    ntl::Match m;

    std::cout << "match:" << (ntl::StringUtils::match(data, reg) ? "true" : "false") << std::endl;

    std::cout << "----------" << std::endl;

    std::cout << "search:" << (ntl::StringUtils::search(data, m, reg) ? "true" : "false") << std::endl;
    for (auto iter = m.cbegin(); iter != m.cend(); iter++)
    {
        std::cout << *iter << std::endl;
    }

    std::cout << "----------" << std::endl;

    std::cout << "replaced:" << ntl::StringUtils::replace(data, ntl::Regex("(.*),(.*)"), "$1 $2") << std::endl;

    std::cout << "----------" << std::endl;

    data = ntl::StringUtils::replace_all(data, ntl::Regex("(.*),(.*)"), "$1 $2");
    std::cout << "replace all:" << data << std::endl;

    std::cout << "----------" << std::endl;

    std::vector<ntl::String> result = ntl::StringUtils::split("a b c d e", "[ ]+");
    for (auto iter = result.cbegin(); iter != result.cend(); iter++)
    {
        std::cout << "\t" << *iter << std::endl;
    }

    std::cout << "----------" << std::endl;

    std::vector<ntl::String> result2 = ntl::StringUtils::split("a b c d e", "[,]+");
    for (auto iter = result2.cbegin(); iter != result2.cend(); iter++)
    {
        std::cout << "\t" << *iter << std::endl;
    }

    std::cout << "----------" << std::endl;

    std::vector<ntl::String> result3 = ntl::StringUtils::split_by_line("a\nb\nc");
    for (auto iter = result3.cbegin(); iter != result3.cend(); iter++)
    {
        std::cout << "\t" << *iter << std::endl;
    }

    return 0;
}