#ifndef __NEUTRONTL_EXCEPTION_NULLPOINTEREXCEPTION_HPP__
#define __NEUTRONTL_EXCEPTION_NULLPOINTEREXCEPTION_HPP__

#include "Exception.hpp"

namespace ntl
{
    /// @brief 空指针异常
    class NullPointerException : public Exception
    {
    public:
        using SelfType = NullPointerException;
        using ParentType = Exception;

    public:
        NullPointerException() = default;
        NullPointerException(const std::wstring &where);
        NullPointerException(const NullPointerException &from) = default;
        ~NullPointerException() = default;

    public:
        NullPointerException &operator=(const NullPointerException &from) = default;
    };

} // namespace ntl

#endif