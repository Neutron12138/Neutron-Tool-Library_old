#ifndef __NEUTRONTL_NODE_TREE_HPP__
#define __NEUTRONTL_NODE_TREE_HPP__

#include "Node.hpp"

namespace ntl
{
    /// @brief 节点树类型
    /// @tparam m_ChildNodeType 子节点类型
    template <typename m_ChildNodeType>
    class Tree : public Node<m_ChildNodeType>
    {
    public:
        using ChildNodeType = m_ChildNodeType;

        using SelfType = Tree<ChildNodeType>;
        using ParentType = Node<ChildNodeType>;

    public:
        Tree() = default;
        Tree(const String &name);
        Tree(const SelfType &from) = default;
        virtual ~Tree() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        virtual bool has_parent() const;
    };
} // namespace ntl

#endif