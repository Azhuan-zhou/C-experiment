#include "BinNode.h"

template <typename Key, typename E>
class BSTNode : public BinNode<E>{
private:
    Key k;                  // 结点的键值
    E it;                   // 结点的值
    BSTNode* lc;            // 指向左孩子的指针
    BSTNode* rc;            // 指向右孩子的指针

public:
    // 构造函数1:根节点为空
    BSTNode()
    {
        lc = rc = NULL;
    }
    // 构造函数2:根节点为叶子结点
    BSTNode(Key K, E e, BSTNode* l =NULL, BSTNode* r =NULL)
    {
        k = K;
        it = e;
        lc = l;
        rc = r;
    }
    // 析构函数
    ~BSTNode() {}
    // 获取当前结点的值
    E& element()
    {
        return it;
    }
    // 设置当前结点的值，传入键值
    void setElement(const E& e)
    {
        it = e;
    }
    // 获取当前结点的键值
    Key& key()
    {
        return k;
    }
    // 设置当前结点的键值
    void setKey(const Key& K)
    {
        k = K;
    }
    // 返回左孩子
    BSTNode* left() const
    {
        return lc;
    }
    // 设置左孩子结点，传入一个BinNode类型的元素
    void setLeft(BinNode<E>* b)
    {
        lc = (BSTNode*)b;
    }
    // 返回右孩子
    BSTNode* right() const
    {
        return rc;
    }
    // 设置右孩子结点，传入一个BinNode类型的元素
    void setRight(BinNode<E>* b)
    {
        rc = (BSTNode*)b;
    }
    // 判断当前结点是否为叶子结点
    bool isLeaf()
    {
        return (lc == NULL) && (rc == NULL);
    }
};