#ifndef __NEUTRONTL_NODE_TREE_CPP__
#define __NEUTRONTL_NODE_TREE_CPP__

#include "Node.hpp"

namespace ntl
{
    template <typename m_ChildNodeType>
    Tree<m_ChildNodeType>::Tree(
        const String &name)
        : Tree<m_ChildNodeType>::ParentType(name) {}

    template <typename m_ChildNodeType>
    bool
    Tree<m_ChildNodeType>::has_parent() const
    {
        return false;
    }
} // namespace ntl

#endif