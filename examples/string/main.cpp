#include <iostream>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

int main()
{
    ntl::String data(L"a,b,c,d,e");
    ntl::Regex reg(L"(.*),(.*)");
    ntl::Match m;

    std::wcout << L"match:" << (ntl::StringUtils::match(data, reg) ? L"true" : L"false") << std::endl;

    std::wcout << L"----------" << std::endl;

    std::wcout << L"search:" << (ntl::StringUtils::search(data, m, reg) ? L"true" : L"false") << std::endl;
    for (auto iter = m.cbegin(); iter != m.cend(); iter++)
    {
        std::wcout << *iter << std::endl;
    }

    std::wcout << L"----------" << std::endl;

    std::wcout << L"replaced:" << ntl::StringUtils::replace(data, ntl::Regex(L"(.*),(.*)"), L"$1 $2") << std::endl;

    std::wcout << L"----------" << std::endl;

    data = ntl::StringUtils::replace_all(data, ntl::Regex(L"(.*),(.*)"), L"$1 $2");
    std::wcout << L"replace all:" << data << std::endl;

    std::wcout << L"----------" << std::endl;

    std::vector<ntl::String> result = ntl::StringUtils::split(L"a b c d e", L"[ ]+");
    for (auto iter = result.cbegin(); iter != result.cend(); iter++)
    {
        std::wcout << "\t" << *iter << std::endl;
    }

    std::wcout << L"----------" << std::endl;

    std::vector<ntl::String> result2 = ntl::StringUtils::split(L"a b c d e", L"[,]+");
    for (auto iter = result2.cbegin(); iter != result2.cend(); iter++)
    {
        std::wcout << "\t" << *iter << std::endl;
    }

    std::wcout << L"----------" << std::endl;

    std::vector<ntl::String> result3 = ntl::StringUtils::split_by_line(L"a\nb\nc");
    for (auto iter = result3.cbegin(); iter != result3.cend(); iter++)
    {
        std::wcout << "\t" << *iter << std::endl;
    }

    return 0;
}