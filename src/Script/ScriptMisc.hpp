#ifndef __NEUTRONTL_SCRIPT_SCRIPTMISC_HPP__
#define __NEUTRONTL_SCRIPT_SCRIPTMISC_HPP__

#include <any>
#include <vector>
#include "../Base/Type.hpp"

namespace ntl
{
    namespace script
    {
        /// @brief 变量内存的指针
        using MemoryPointer = std::vector<Byte>;

        /// @brief 参数数组
        using ArgumentsArray = std::vector<std::any>;
    } // namespace script

} // namespace ntl

#endif