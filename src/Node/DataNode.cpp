#ifndef __NEUTRONTL_NODE_DATANODE_CPP__
#define __NEUTRONTL_NODE_DATANODE_CPP__

#include "DataNode.hpp"

namespace ntl
{
    template <typename m_DataType>
    DataNode<m_DataType>::DataNode(const typename DataNode<m_DataType>::DataType &data) : m_data(data) {}

    template <typename m_DataType>
    inline typename DataNode<m_DataType>::DataType &DataNode<m_DataType>::get()
    {
        return m_data;
    }

    template <typename m_DataType>
    inline const typename DataNode<m_DataType>::DataType &DataNode<m_DataType>::get_data() const
    {
        return m_data;
    }

    template <typename m_DataType>
    inline void DataNode<m_DataType>::set_data(const typename DataNode<m_DataType>::DataType &data)
    {
        m_data = data;
    }
} // namespace ntl

#endif