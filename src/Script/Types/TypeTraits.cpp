#ifndef __NEUTRONTL_SCRIPT_TYPETRAITS_CPP__
#define __NEUTRONTL_SCRIPT_TYPETRAITS_CPP__

#include "TypeTraits.hpp"

namespace ntl
{
    namespace script
    {
        namespace Types
        {
            template <typename TraitsType>
            bool
            TypeTraits::is_memory_size_legal(
                const MemoryPointer &memory)
            {
                return memory.size() >= TraitsType::TYPE_SIZE;
            }
        } // namespace Types

    } // namespace script

} // namespace ntl

#endif