#ifndef __NEUTRONTL_SCRIPT_INTEGER_CPP__
#define __NEUTRONTL_SCRIPT_INTEGER_CPP__

#include "Integer.hpp"

namespace ntl
{
    namespace script
    {
        namespace Types
        {
            void
            Integer::construction(
                MemoryPointer &memory)
            {
                if (!is_memory_size_legal<Integer>(memory))
                    return;

                as_internal_type(memory) = 0L;
            }

            void
            Integer::construction(
                MemoryPointer &memory,
                const ArgumentsArray arguments)
            {
                if (!is_memory_size_legal<Integer>(memory))
                    return;

                if (arguments.size() == 1)
                {
                    as_internal_type(memory) =
                        std::any_cast<Integer::InternalType>(arguments.at(0));
                }
                else
                {
                }
            }

            void
            Integer::destruction(
                MemoryPointer &memory)
            {
                if (!is_memory_size_legal<Integer>(memory))
                    return;

                memory.clear();
            }

            void
            Integer::operation(
                MemoryPointer &memory,
                TypeTraits::Operator operation, const ArgumentsArray arguments)
            {
                if (!is_memory_size_legal<Integer>(memory))
                    return;
            }

            Integer::InternalType &
            Integer::as_internal_type(
                const MemoryPointer &memory)
            {
                Integer::Integer::InternalType *ptr =
                    const_cast<Integer::InternalType *>(
                        reinterpret_cast<const Integer::InternalType *>(
                            memory.data()));
                return *ptr;
            }
        } // namespace Types

    } // namespace script

} // namespace ntl

#endif