#ifndef __NEUTRONTL_FILE_FILE_HPP__
#define __NEUTRONTL_FILE_FILE_HPP__

#include <vector>
#include <fstream>
#include <filesystem>
#include "../Base/Object.hpp"

namespace ntl
{
    /// @brief 阅读文件所有字符
    /// @param path 文件路径
    /// @return 文件所有字符
    std::vector<char> read_all_from_file(const std::filesystem::path &path);

    template <typename DataType>
    DataType read_from_file(const std::filesystem::path &path);

    template <typename DataType>
    void write_to_file(const DataType &data, const std::filesystem::path &path);

} // namespace ntl

#endif
