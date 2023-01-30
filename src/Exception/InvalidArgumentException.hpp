#ifndef __NEUTRONTL_EXCEPTION_INVALIDARGUMENTEXCEPTION_HPP__
#define __NEUTRONTL_EXCEPTION_INVALIDARGUMENTEXCEPTION_HPP__

#include "Exception.hpp"

namespace ntl
{
    /// @brief 无效参数异常
    class InvalidArgumentException : public Exception
    {
    public:
        using SelfType = InvalidArgumentException;
        using ParentType = Exception;

    public:
        InvalidArgumentException() = default;
        InvalidArgumentException(const String &why, const String &where);
        InvalidArgumentException(const SelfType &from) = default;
        ~InvalidArgumentException() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
    };

} // namespace ntl

#endif