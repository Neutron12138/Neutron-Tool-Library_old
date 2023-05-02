#ifndef __NEUTRONTL_MISC_RESULT_CPP__
#define __NEUTRONTL_MISC_RESULT_CPP__

#include "Result.hpp"

namespace ntl
{
    template <typename m_DataType, typename m_ReasonType>
    Result<m_DataType, m_ReasonType>::Result(
        const typename Result<m_DataType, m_ReasonType>::DataType &d)
        : data(d) {}

    template <typename m_DataType, typename m_ReasonType>
    Result<m_DataType, m_ReasonType>::Result(
        const typename Result<m_DataType, m_ReasonType>::ReasonType &r)
        : success(false),
          reason(r) {}

    template <typename m_DataType, typename m_ReasonType>
    Result<m_DataType, m_ReasonType>::Result(
        bool s,
        const typename Result<m_DataType, m_ReasonType>::DataType &d,
        const typename Result<m_DataType, m_ReasonType>::ReasonType &r)
        : success(s),
          data(d),
          reason(r) {}

} // namespace ntl

#endif
