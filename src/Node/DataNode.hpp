#ifndef __NEUTRONTL_NODE_DATANODE_HPP__
#define __NEUTRONTL_NODE_DATANODE_HPP__

#include "DefaultNode.hpp"

namespace ntl
{
    /// @brief 数据节点
    /// @tparam m_DataType 数据类型
    template <typename m_DataType>
    class DataNode : public DefaultNode
    {
    public:
        using DataType = m_DataType;

        using SelfType = DataNode<DataType>;
        using ParentType = DefaultNode;

    protected:
        DataType m_data;

    public:
        DataNode() = default;
        explicit DataNode(const DataType &data);
        explicit DataNode(const SelfType &from) = default;
        ~DataNode() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        /// @brief 获取数据
        /// @return 数据
        DataType &get();

        /// @brief 获取数据
        /// @return 数据
        const DataType &get_data() const;

        /// @brief 设置数据
        /// @param data 数据
        virtual void set_data(const DataType &data);
    };
} // namespace ntl

#endif