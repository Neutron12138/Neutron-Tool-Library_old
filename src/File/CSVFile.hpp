#ifndef __NEUTRONTL_FILE_CSVFILE_HPP__
#define __NEUTRONTL_FILE_CSVFILE_HPP__

#include "File.hpp"

namespace ntl
{
    class CSVFile : public File
    {
    public:
        using SelfType = CSVFile;
        using ParentType = File;

    public:
        CSVFile() = default;
        CSVFile(SizeT rows, SizeT columns);
        CSVFile(const SelfType &from) = default;
        ~CSVFile() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
    };

} // namespace ntl

#endif
