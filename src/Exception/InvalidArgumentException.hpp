#ifndef __NEUTRONTL_EXCEPTION_INVALIDARGUMENTEXCEPTION_HPP__
#define __NEUTRONTL_EXCEPTION_INVALIDARGUMENTEXCEPTION_HPP__

#include "Exception.hpp"

namespace ntl
{
    /// @brief 无效参数异常
    class NTL_ALIGN InvalidArgumentException : public Exception
    {
    public:
        using SelfType = InvalidArgumentException;
        using ParentType = Exception;

    public:
        InvalidArgumentException() = default;
        NTL_EXPLICIT InvalidArgumentException(const String &why, const String &where);
        NTL_EXPLICIT InvalidArgumentException(const SelfType &from) = default;
        ~InvalidArgumentException() NTL_OVERRIDE = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
    };

} // namespace ntl

#endif