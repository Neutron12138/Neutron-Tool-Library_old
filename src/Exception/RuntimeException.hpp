#ifndef __NEUTRONTL_EXCEPTION_RUNTIMEEXCEPTION_HPP__
#define __NEUTRONTL_EXCEPTION_RUNTIMEEXCEPTION_HPP__

#include "Exception.hpp"

namespace ntl
{
    /// @brief 运行时异常
    class NTL_ALIGN RuntimeException : public Exception
    {
    public:
        using SelfType = RuntimeException;
        using ParentType = Exception;

    public:
        RuntimeException() = default;
        RuntimeException(const String &why, const String &where);
        RuntimeException(const SelfType &from) = default;
        ~RuntimeException() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
    };

} // namespace ntl

#endif
