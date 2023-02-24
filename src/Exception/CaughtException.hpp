#ifndef __NEUTRONTL_EXCEPTION_CAUGHTEXCEPTION_HPP__
#define __NEUTRONTL_EXCEPTION_CAUGHTEXCEPTION_HPP__

#include <vector>
#include "Exception.hpp"

namespace ntl
{
    /// @brief 捕捉到异常
    class CaughtException : public Exception
    {
    public:
        using SelfType = CaughtException;
        using ParentType = Exception;

    protected:
        /// @brief 发生异常的地方数组
        std::vector<String> m_where_array;
        /// @brief 捕捉到的异常
        Exception m_caught_exception;

    public:
        CaughtException() = default;
        explicit CaughtException(const Exception &exception, const String &where);
        explicit CaughtException(const CaughtException &exception, const String &where);
        explicit CaughtException(const SelfType &from) = default;
        ~CaughtException() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        /// @brief 获取发生异常的地方数组
        /// @return 发生异常的地方数组
        const std::vector<String> &get_where_array() const;

        /// @brief 获取捕捉到的异常
        /// @return 捕捉到的异常
        const Exception &get_caught_exception() const;

    public:
        void print_self(OutputStream &os) const override;
    };

} // namespace ntl

#endif