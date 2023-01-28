#ifndef __NEUTRONTL_EXCEPTION_EXCEPTION_HPP__
#define __NEUTRONTL_EXCEPTION_EXCEPTION_HPP__

#include <string>
#include <exception>
#include <stdexcept>
#include "../Base/Object.hpp"

namespace ntl
{
    /// @brief 基础异常类
    class Exception : public Object
    {
    public:
        using SelfType = Exception;
        using ParentType = Object;

    protected:
        /// @brief 异常说明
        std::wstring m_what;
        /// @brief 异常原因
        std::wstring m_why;
        /// @brief 异常位置
        std::wstring m_where;

    public:
        Exception() = default;
        Exception(const std::wstring &what, const std::wstring &why, const std::wstring &where);
        Exception(const SelfType &from) = default;
        ~Exception() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        /// @brief 获取发生了什么异常
        /// @return 异常说明
        const std::wstring &what() const;

        /// @brief 获取为什么发生异常
        /// @return 异常原因
        const std::wstring &why() const;

        /// @brief 获取发生异常的位置在哪（在哪个文件，哪个函数）
        /// @return 异常位置
        const std::wstring &where() const;
    };

    std::wostream &operator<<(std::wostream &os, const Exception &exception);
} // namespace ntl

#endif