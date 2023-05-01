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
        using ChildNodeHolder = std::map<String, ChildNodeType>;

        using SelfType = Node<ChildNodeType>;
        using ParentType = BasicNode<ChildNodeType>;

    protected:
        ChildNodeHolder m_child_nodes;

    public:
        Node() = default;
        Node(const String &name);
        Node(const SelfType &from) = default;
        virtual ~Node() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
        virtual ChildNodeType &operator[](const String &name) override;

    public:
        const ChildNodeHolder &get_child_nodes() const;

    public:
        virtual const ChildNodeType &get_child_node(const String &name) const override;
        virtual void set_child_node(const String &name, const ChildNodeType &child_node) override;
        virtual void add_child_node(const String &name, const ChildNodeType &child_node) override;
        virtual void remove_child_node(const String &name) override;
        virtual bool is_exist(const String &name) const override;
        virtual bool has_childs() const override;
        virtual void clear_all() override;
    };

} // namespace ntl

#endif