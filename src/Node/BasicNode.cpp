#ifndef __NEUTRONTL_NODE_BASICNODE_CPP__
#define __NEUTRONTL_NODE_BASICNODE_CPP__

#include "BasicNode.hpp"

namespace ntl
{
    template <typename m_ChildNodeType>
    BasicNode<m_ChildNodeType>::BasicNode(
        const String &name)
        : BasicNode<m_ChildNodeType>::ParentType(name) {}

} // namespace ntl

#endif