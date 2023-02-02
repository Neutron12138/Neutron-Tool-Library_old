#ifndef __NEUTRONTL_NODE_NODE_HPP__
#define __NEUTRONTL_NODE_NODE_HPP__

#include <map>
#include <string>
#include "BasicNode.hpp"

namespace ntl
{
    /// @brief 节点类
    /// @tparam m_ChildNodeType 子节点类
    template <typename m_ChildNodeType>
    class NTL_ALIGN Node : public BasicNode<m_ChildNodeType>
    {
    public:
        using ChildNodeType = m_ChildNodeType;

        using SelfType = Node<ChildNodeType>;
        using ParentType = BasicNode<ChildNodeType>;

    protected:
        std::map<String, ChildNodeType> m_child_nodes;

    public:
        Node() = default;
        NTL_EXPLICIT Node(const String &name);
        NTL_EXPLICIT Node(const SelfType &from) = default;
        NTL_VIRTUAL ~Node() NTL_OVERRIDE = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
        NTL_VIRTUAL ChildNodeType &operator[](const String &name) NTL_OVERRIDE;

    public:
        NTL_INLINE const std::map<String, ChildNodeType> &get_child_nodes() const;

    public:
        NTL_VIRTUAL const ChildNodeType &get_child_node(const String &name) const NTL_OVERRIDE;
        NTL_VIRTUAL void set_child_node(const String &name, const ChildNodeType &child_node) NTL_OVERRIDE;
        NTL_VIRTUAL void add_child_node(const String &name, const ChildNodeType &child_node) NTL_OVERRIDE;
        NTL_VIRTUAL void remove_child_node(const String &name) NTL_OVERRIDE;
        NTL_VIRTUAL bool is_exist(const String &name) const NTL_OVERRIDE;
        NTL_INLINE NTL_VIRTUAL bool has_childs() const NTL_OVERRIDE;
        NTL_VIRTUAL void clear_all() NTL_OVERRIDE;
    };

} // namespace ntl

#endif