#ifndef __NEUTRONTL_SCRIPT_TYPEID_HPP__
#define __NEUTRONTL_SCRIPT_TYPEID_HPP__

#include "../Base/Type.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    namespace script
    {
        namespace TypeID
        {
            /// @brief 整数，对应Int64
            static const String integer = NTL_STRING("integer");

            /// @brief 浮点数，对应Float64
            static const String floating = NTL_STRING("floating");

        } // namespace TypeID

    } // namespace script

} // namespace ntl

#endif