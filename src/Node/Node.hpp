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
    class Node : public BasicNode<m_ChildNodeType>
    {
    public:
        using ChildNodeType = m_ChildNodeType;

        using SelfType = Node<ChildNodeType>;
        using ParentType = BasicNode<ChildNodeType>;

    protected:
        std::map<String, ChildNodeType> m_child_nodes;

    public:
        Node() = default;
        Node(const String &name);
        Node(const SelfType &from) = default;
        virtual ~Node() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
        virtual ChildNodeType &operator[](const String &name);

    public:
        const std::map<String, ChildNodeType> &get_child_nodes() const;

    public:
        virtual const ChildNodeType &get_child_node(const String &name) const;
        virtual void set_child_node(const String &name, const ChildNodeType &child_node);
        virtual void add_child_node(const String &name, const ChildNodeType &child_node);
        virtual void remove_child_node(const String &name);
        virtual bool is_exist(const String &name) const;
        virtual bool has_childs() const;
        virtual void clear_all();
    };

} // namespace ntl

#endif