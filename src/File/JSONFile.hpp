#ifndef __NEUTRONTL_FILE_JSON_HPP__
#define __NEUTRONTL_FILE_JSON_HPP__

#include "File.hpp"

namespace ntl
{
    class JSONFile : public File
    {
    public:
        using SelfType = JSONFile;
        using ParentType = File;

    public:
        JSONFile() = default;
        JSONFile(const SelfType &from) = default;
        ~JSONFile() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
    };

} // namespace ntl

#endif