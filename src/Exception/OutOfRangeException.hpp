#ifndef __NEUTRONTL_EXCEPTION_OUTOFRANGEEXCEPTION_HPP__
#define __NEUTRONTL_EXCEPTION_OUTOFRANGEEXCEPTION_HPP__

#include "Exception.hpp"

namespace ntl
{
    /// @brief 越界访问异常
    class OutOfRangeException : public Exception
    {
    public:
        using SelfType = OutOfRangeException;
        using ParentType = Exception;

    public:
        OutOfRangeException() = default;
        OutOfRangeException(const std::wstring &why, const std::wstring &where);
        OutOfRangeException(const OutOfRangeException &from) = default;
        ~OutOfRangeException() = default;

    public:
        OutOfRangeException &operator=(const OutOfRangeException &from) = default;
    };

} // namespace ntl

#endif