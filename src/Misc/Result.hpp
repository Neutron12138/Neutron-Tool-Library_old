#ifndef __NEUTRONTL_MISC_RESULT_HPP__
#define __NEUTRONTL_MISC_RESULT_HPP__

#include <optional>
#include "../Base/Object.hpp"

namespace ntl
{
    /// @brief 返回值，适合发生错误时不适宜抛出异常的情况使用
    template <typename m_DataType, typename m_ReasonType = String>
    class Result : public Object
    {
    public:
        using DataType = m_DataType;
        using ReasonType = m_ReasonType;

        using SelfType = Result<DataType>;
        using ParentType = Object;

    public:
        /// @brief 是否成功
        bool success = true;

        /// @brief 返回值数据
        std::optional<DataType> data;

        /// @brief 失败原因
        std::optional<ReasonType> reason;

    public:
        Result(const DataType &d);
        Result(const ReasonType &r);
        Result(bool s, const DataType &d, const ReasonType &r);
    };

} // namespace ntl

#endif
