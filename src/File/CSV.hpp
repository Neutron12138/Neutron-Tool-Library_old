#ifndef __NEUTRONTL_FILE_CSV_HPP__
#define __NEUTRONTL_FILE_CSV_HPP__

#include "../Base/Object.hpp"

namespace ntl
{
    class CSV : public Object
    {
    public:
        using SelfType = CSV;
        using ParentType = Object;

    public:
        CSV() = default;
        CSV(SizeT rows, SizeT columns);
        CSV(const SelfType &from) = default;
        ~CSV() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
    };

} // namespace ntl

#endif
