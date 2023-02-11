#ifndef __NEUTRONTL_SCRIPT_VARIABLE_HPP__
#define __NEUTRONTL_SCRIPT_VARIABLE_HPP__

#include <vector>
#include "../Base/Object.hpp"
#include "Types/TypeTraits.hpp"
#include "ScriptMisc.hpp"

namespace ntl
{
    namespace script
    {
        /// @brief 变量
        class Variable : public Object
        {
        public:
            using SelfType = Variable;
            using ParentType = Object;

        protected:
            /// @brief 类型特点
            Types::TypeTraits &m_type_traits;
            /// @brief 内存
            MemoryPointer m_memory;

        public:
            Variable() = default;
            explicit Variable(const SelfType &from) = default;
            ~Variable() override = default;

        public:
            SelfType &operator=(const SelfType &from) = default;
        };
    } // namespace script

} // namespace ntl

#endif