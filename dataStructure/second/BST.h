#include "BSTNode.h"
template <typename Key, typename E>
class BST {
private:
    BSTNode<Key,E>* root;   // 根结点
    int nodeNum;         // 二叉检索数的结点个数
    // 辅助函数
    void clearHelp(BSTNode<Key, E>*);
    BSTNode<Key,E>* insertHelp(BSTNode<Key, E>*,
                               const Key&, const E&);
    BSTNode<Key,E>* deletemin(BSTNode<Key, E>*);
    BSTNode<Key,E>* getmin(BSTNode<Key, E>*);
    BSTNode<Key,E>* removeHelp(BSTNode<Key, E>*, const Key&);
    E findhelp(BSTNode<Key, E>*, const Key&) const;
    void printhelp(BSTNode<Key, E>*, int) const;

public:
    // 二叉检索数的构造
    BST(){ root = NULL; nodeNum = 0; }
    // 二叉检索数的析构
    ~BST() { clearHelp(root); }
    // 重新初始化二叉检索树
    void clear()
    {
        clearHelp(root);
        root = NULL;
        nodeNum = 0;
    }

    // 在二叉检索树中插入一条记录，k：键值，e：元素
    void insert(const Key& k, const E& e) {
        root = insertHelp(root, k, e);
        nodeNum++;
    }
    // 获取头节点
    BSTNode<Key,E>* getRoot(){
        return root;
    }


    // 在二叉检索树中删除一条记录，k：键值，e：元素，如果有这条记录返回删除的e，否则返回Null
    E remove(const Key& k) {
        E temp = findhelp(root, k);   // 在二叉检索树中查找键值K
        if (temp != NULL) {
            root = removeHelp(root, k);
            nodeNum--;
        }
        return temp;
    }
    // 移除头节点的记录，返回头节点的值1;如果二叉检索数为空，返回Null
    E removeAny() {  // Delete min value
        if (root != NULL) {
            E temp = root->element();
            root = removeHelp(root, root->key());
            nodeNum--;
            return temp;
        }
        else return NULL;
    }
    // 传入键值K,在二叉检索树中寻找键值等于k的记录
    E find(const Key& k) const
    {
        return findhelp(root, k);
    }
    // 返回二叉检索树的结点个数
    int size() { return nodeNum; }
    // 打印二叉检索树
    void print() const {
        if (root == NULL) cout << "The BST is empty.\n";
        else
            printhelp(root, 0);
    }
};

// 辅助函数：清空二叉检索树的结点
template <typename Key, typename E>
void BST<Key, E>::
clearHelp(BSTNode<Key, E>* root) {
    if (root == NULL) return;
    clearHelp(root->left());
    clearHelp(root->right());
    // 后根遍历
    delete root;
}

// 辅助函数：插入键值为K的记录it
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::insertHelp(
        BSTNode<Key, E>* root, const Key& k, const E& it) {
    if (root == NULL)  // 如果树为空，在根结点插入
        return new BSTNode<Key, E>(k, it, NULL, NULL);
    // 键值k小于当前根结点的键值，在左边继续搜索，直到空结点
    if (k < root->key())
        root->setLeft(insertHelp(root->left(), k, it));
    else
        root->setRight(insertHelp(root->right(), k, it));
    return root;       // 返回当前进行插入操作的根结点，最后返回整个树的根节点
}

// 获取二叉检索树中值最小的元素的结点
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::
getmin(BSTNode<Key, E>* rt) {
    if (rt->left() == NULL)
        return rt;
    else
        return getmin(rt->left());
}
// 删除二叉检索树中最小元素的结点
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::
deletemin(BSTNode<Key, E>* rt) {
    BSTNode<Key, E>* temp;
    // 如果当前根结点的左孩子为空，则说明该结点是元素最小的结点；
    // 返回其右孩子结点
    if (rt->left() == NULL)
        return rt->right();
    else {
        temp=deletemin(rt->left()); // 一直向左边搜索,直到找到了包含最小记录的结点rt->left，返回了其rt的左孩子的右孩子
        rt->setLeft(temp);
        return rt;
    }
}

// 移除键值为K的元素
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::
removeHelp(BSTNode<Key, E>* rt, const Key& k) {
    // 二叉检索树中没有键值为k的记录
    if (rt == NULL) return NULL;
    // 键值K小于当前根结点的键值
    else if (k < rt->key())
        rt->setLeft(removeHelp(rt->left(), k));
    // 键值K大于当前根结点的键值
    else if (k > rt->key())
        rt->setRight(removeHelp(rt->right(), k));
    // 当前根节点的的键值为K
    else {
        BSTNode<Key, E>* temp = rt;
        // 当前根节点只有右子树
        if (rt->left() == NULL) {
            rt = rt->right();         // 根节点更改为当前子树根节点的右孩子
            delete temp;
        }
        // 当前根结点只有左子树
        else if (rt->right() == NULL) {
            rt = rt->left();          // 根节点更改为当前子树根节点的左孩子
            delete temp;
        }
        // 当前根节点左右子树都为非空
        else {
            BSTNode<Key, E>* temp = getmin(rt->right()); // 获取当前根节点右子树中最小的结点
            // 将当前根结点更改为右子树中最小的结点
            rt->setElement(temp->element());
            rt->setKey(temp->key());
            rt->setRight(deletemin(rt->right()));
            // 删除右子树中最小的结点
            delete temp;
        }
    }
    return rt;
}

// 寻找键值为K的结点，并返回其元素记录
template <typename Key, typename E>
E BST<Key, E>::findhelp(BSTNode<Key, E>* root,
                        const Key& k) const {
    if (root == NULL) return NULL;          // 当前树的根结点为空，二叉树中没有键值为K的记录1
    // 键值K小于当前根结点的键值
    if (k < root->key())
        return findhelp(root->left(), k);
    // 键值K大于当前根结点的键值
    else if (k > root->key())
        return findhelp(root->right(), k);
    // 键值K等于当前根结点的键值
    else return root->element();
}

// 打印当前的二叉检索树
template <typename Key, typename E>
void BST<Key, E>::
printhelp(BSTNode<Key, E>* root, int level) const {
    // 子树为空
    if (root == NULL) return;
    printhelp(root->left(), level+1);
    // 中序遍历
    for (int i=0; i<level; i++)
        cout << "    ";
    cout << root->key() << "\n";
    printhelp(root->right(), level+1);
}
