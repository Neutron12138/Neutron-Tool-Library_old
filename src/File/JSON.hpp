#ifndef __NEUTRONTL_FILE_JSON_HPP__
#define __NEUTRONTL_FILE_JSON_HPP__

#include "../Base/Object.hpp"

namespace ntl
{
    class JSON : public Object
    {
    public:
        using SelfType = JSON;
        using ParentType = Object;

    public:
        JSON() = default;
        explicit JSON(const SelfType &from) = default;
        ~JSON() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
    };

} // namespace ntl

#endif