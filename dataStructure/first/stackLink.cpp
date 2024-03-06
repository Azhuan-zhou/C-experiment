#include <iostream>
#define defaultSize 100
using namespace std;

template <typename E> 
class Link
{
public:
    E element; // 结点的数据域
    Link *next; // 结点的指针域
    // 链表析构函数
    Link(const E& elemval, Link* nextval =NULL)
    { 
        element = elemval; 
        next = nextval; 
    }
    Link(Link* nextval =NULL) 
    { 
        next = nextval; 
    }
};

// 链表栈
template <typename E> 
class LStack 
{
private:
    Link<E>* top; // 指向栈顶的头节点
    int size; // 栈中元素个数
public:
    // 栈的构造函数
    LStack(int sz =defaultSize) 
    { 
        top = NULL; 
        size = 0; 
    }
    // 栈的析构函数
    ~LStack() 
    { 
        clear(); 
    } 
    // 清空栈中的元素
    void clear() 
    { 
        while (top != NULL) 
        {  
            Link<E>* temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
    }
    // 将it入栈
    void push(const E& it) 
    {
        top = new Link<E>(it, top); // 新结点的指针域指向栈中上一个元素
        size++;
    }
    // 栈顶元素出栈
    E pop() 
    {
        if(top==NULL)
        {
            cout<< "Stack is empty";
            exit(-1);
        }
        E it = top->element;
        Link<E>* ltemp = top->next;  
        delete top;
        top = ltemp;  // top向下移动
        size--;
        return it;
    }
    // 获取栈顶元素
    const E& topValue() const 
    { 
        if(top==NULL)
        {
            cout<<"Stack is empty";
            exit(-1);
        }
        return top->element;
    }
    // 获取栈中元素个数
    int length() const { return size; } 
};

