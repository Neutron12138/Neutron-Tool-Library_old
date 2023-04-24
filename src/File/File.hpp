#ifndef __NEUTRONTL_FILE_FILE_HPP__
#define __NEUTRONTL_FILE_FILE_HPP__

#include <vector>
#include <filesystem>
#include "../Base/Object.hpp"

namespace ntl
{
    class File : public Object
    {
    public:
        using SelfType = File;
        using ParentType = Object;

    public:
        File() = default;
        explicit File(const SelfType &from) = default;
        ~File() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        /// @brief 打开一个文件
        /// @param filename 文件名
        /// @return 是否成功打开，若不存在则抛出FileNotFoundException
        virtual bool open_file(const std::string &filename) = 0;

        /// @brief 保存到文件
        /// @param filename 文件名
        /// @return 是否成功保存
        virtual bool save_to_file(const std::string &filename) = 0;

        /// @brief 阅读文件所有字符
        /// @return 文件所有字符
        virtual std::vector<Char> read_all() = 0;
    };

} // namespace ntl

#endif