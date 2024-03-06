#include<iostream>
using namespace std;

// 二叉树结点的抽象类
template <typename E>
class BinNode {
public:
    virtual ~BinNode() {} // 析构

    // 返回结点的值
    virtual E& element() = 0;

    // 为结点赋值
    virtual void setElement(const E&) = 0;

    // 返回结点的左孩子
    virtual BinNode* left() const = 0;

    // 设置结点的左孩子
    virtual void setLeft(BinNode*) = 0;

    // 返回结点的右孩子
    virtual BinNode* right() const = 0;

    // 设置结点的右孩子
    virtual void setRight(BinNode*) = 0;

    // 如果结点是叶子结点，返回True
    virtual bool isLeaf() = 0;
};