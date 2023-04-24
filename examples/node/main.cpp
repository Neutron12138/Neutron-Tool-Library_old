#include <iostream>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

class MyNode
    : public ntl::DefaultNode
{
public:
    ntl::String data;

public:
    MyNode(
        const ntl::String &n,
        const ntl::SharedPointer<ntl::DefaultNode> &p,
        const ntl::String &d)
        : ntl::DefaultNode(n, ntl::WeakPointer(p)), data(d) {}
    MyNode(
        const MyNode &from) = default;

    virtual ~MyNode()
    {
        std::cout << "~MyNode()"
                  << "\t" << m_name << std::endl;
    }
};

/// @brief 遍历并输出
void traverse_all(const ntl::SharedPointer<ntl::DefaultNode> &root, int tabs = 0);

int main()
{
    ntl::SharedPointer<ntl::DefaultNode> root(new MyNode("root", ntl::SharedPointer<ntl::DefaultNode>(nullptr), "root data"));

    ntl::SharedPointer<ntl::DefaultNode> child1(new MyNode("child1", root, "child1 data"));
    ntl::SharedPointer<ntl::DefaultNode> child2(new MyNode("child2", root, "child2 data"));

    ntl::SharedPointer<ntl::DefaultNode> c1child1(new MyNode("c1child1", child1, "c1child1 data"));
    ntl::SharedPointer<ntl::DefaultNode> c1child2(new MyNode("c1child2", child1, "c1child2 data"));
    ntl::SharedPointer<ntl::DefaultNode> c2child1(new MyNode("c2child1", child2, "c2child1 data"));
    ntl::SharedPointer<ntl::DefaultNode> c2child2(new MyNode("c2child2", child2, "c2child2 data"));

    root->add_child_node("child1", child1);
    root->add_child_node("child2", child2);

    child1->add_child_node("c1child1", c1child1);
    child1->add_child_node("c1child2", c1child2);
    child2->add_child_node("c2child1", c2child1);
    child2->add_child_node("c2child2", c2child2);

    std::cout << "--------------------" << std::endl;

    traverse_all(root);

    std::cout << "--------------------" << std::endl;

    ntl::reset_parent_node("child2", child2, root, child1);

    traverse_all(root);

    std::cout << "--------------------" << std::endl;

    ntl::SharedPointer<ntl::DefaultNode> node(new ntl::DataNode<int>(666));
    std::cout << "dynamic_cast<ntl::DataNode<int>*>(node.get())->get_data():"
              << dynamic_cast<ntl::DataNode<int> *>(node.get())->get_data() << std::endl;

    std::cout << "--------------------" << std::endl;

    return 0;
}

void traverse_all(
    const ntl::SharedPointer<ntl::DefaultNode> &root,
    int tabs)
{
    for (int i = 0; i < tabs; i++)
        std::cout << "\t";
    std::cout << root->get_name() << "\t\t"
              << dynamic_cast<MyNode *>(root.get())->data << std::endl;

    auto &nodes = root->get_child_nodes();
    for (auto iter = nodes.cbegin(); iter != nodes.cend(); iter++)
    {
        traverse_all(iter->second, tabs + 1);
    }
}
