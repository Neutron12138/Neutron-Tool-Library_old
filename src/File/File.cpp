#ifndef __NEUTRONTL_FILE_FILE_CPP__
#define __NEUTRONTL_FILE_FILE_CPP__

#include "File.hpp"
#include "../Exception/FileException.hpp"
#include "../String/StringUtils.hpp"
#include "../Exception/CaughtException.hpp"

namespace ntl
{
    std::vector<char>
    read_all_from_file(const std::filesystem::path &path)
    {
        std::ifstream fin;

        fin.open(path, std::ios::binary);
        if (fin.fail())
            throw FileException(
                StringUtils::to_string(
                    NTL_STRING("Cannot open "),
                    path),
                NTL_MAKE_STATEMENT_INFO("std::vector<char> read_all_from_file(const std::filesystem::path &path)"));

        try
        {
            std::vector<char> result;
            char temp;
            while (fin.read(&temp, sizeof(Byte)))
                result.push_back(temp);

            fin.close();
            return result;
        }
        catch (const std::exception &exception)
        {
            fin.close();
            throw CaughtException(
                exception,
                NTL_MAKE_STATEMENT_INFO("std::vector<char> read_all_from_file(const std::filesystem::path &path)"));
        }
    }

    template <>
    String
    read_from_file(
        const std::filesystem::path &path)
    {
        InputFileStream fin;
        
        fin.open(path);
        if (fin.fail())
            throw FileException(
                StringUtils::to_string(
                    NTL_STRING("Cannot open "),
                    path),
                NTL_MAKE_STATEMENT_INFO("template <> String read_from_file(const std::filesystem::path &path)"));

        try
        {
            StringStream sstr;
            String temp;

            while (std::getline(fin, temp))
                sstr << temp << std::endl;

            fin.close();
            return sstr.str();
        }
        catch (const std::exception &exception)
        {
            fin.close();
            throw CaughtException(
                exception,
                NTL_MAKE_STATEMENT_INFO("template <> String read_from_file(const std::filesystem::path &path)"));
        }
    }

} // namespace ntl

#endif
