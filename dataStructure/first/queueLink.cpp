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

template <typename E>
class LQueue
{
private:
    Link<E>* front; // 指向队首的指针
    Link<E>* rear; // 指向队尾的指针
    int size; // 队列的长度
public:
    // 队列的构造
    LQueue(int sz =defaultSize) 
    { 
        front = rear = new Link<E>(); 
        size = 0; 
    }
    // 队列的析构
    ~LQueue() 
    { 
        clear(); 
        delete front; 
    } 
    // 清空队列
    void clear() 
    { 
        while(front->next != NULL) 
        { 
            rear = front;
            delete rear;
        }
        rear = front;
        size = 0;
    }
    // it入队
    void enqueue(const E& it) 
    { 
        rear->next = new Link<E>(it, NULL); // rear保存着队列最后一个元素的结点
        rear = rear->next;
        size++;
    }
    // 出队
    E dequeue() 
    {
        if(size == 0)
        {
            cout<<"Queue is empty";
            exit(-1);
        }
        E it = front->next->element; // front的指针域指向第一个结点
        Link<E>* ltemp = front->next; 
        front->next = ltemp->next; // 将front的指针域指向第二个结点
        if (rear == ltemp) 
            rear = front; // 如果队列只有一个结点
        delete ltemp; // 删除第一个结点
        size --;
        return it; 
    }
    // 获取队首元素
    const E& frontValue() const 
    { 
        if(size == 0)
        {
            cout<<"Queue is empty";
            exit(-1);
        }
        return front->next->element;
    }
    // 队列长度
    int length() const 
    { 
        return size; 
    }
};

