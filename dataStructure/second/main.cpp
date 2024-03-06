#include "BST.h"

int sum_tree(BSTNode<int,int*> *b){
    if(b == NULL)
    {
        return 0;
    }
    return *b->element() + sum_tree(b->left())+ sum_tree(b->right());
}


int main(){
    BST<int,int*> tree;
    int sum_num;
    tree.insert(350, new int(350));
    tree.insert(201, new int(201));
    tree.insert(170, new int(170));
    tree.insert(151, new int(151));
    tree.insert(190, new int(190));
    tree.insert(1000, new int(1000));
    tree.insert(900, new int(900));
    tree.insert(950, new int(950));
    tree.insert(10, new int(10));
    tree.print();
    sum_num = sum_tree(tree.getRoot());
    cout<<"二叉检索树的所有结点数值之和为："<<sum_num<<endl;
    tree.print();
}


