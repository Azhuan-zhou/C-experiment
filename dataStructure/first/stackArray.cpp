#include <iostream>
#define defaultSize 100
using namespace std;

// 顺序栈
template <typename E>
class AStack
{
private:
    int maxSize; // 栈的最大元素
    int top; // 栈顶位置索引,是待入栈元素的位置
    E *listArray; // 栈
public:
    // 栈的构造
    AStack(int size =defaultSize) 
    { 
        maxSize = size; 
        top = 0; 
        listArray = new E[size]; 
    }
    // 栈的析构
    ~AStack() 
    { 
        delete [] listArray; 
    } 
    // 清空栈的元素
    void clear() 
    { 
        top = 0; 
    }
    // it入栈 
    void push(const E& it) 
    {
        if(top == maxSize)
        {
            cout<<"Stack is full";
            exit(-1);
        }
        listArray[top++] = it;
    }
    // 出栈
    E pop() 
    { 
        if(top==0)
        {
            cout<<"Stack is empty";
            exit(-1);
        }
        return listArray[--top];
    }
    // 获取栈顶元素
    const E& topValue() const 
    { 
        if(top==0)
        {
            cout<<"Stack is empty";
            exit(-1);
        }
        return listArray[top-1];
    }
    // 获取栈的长度
    int length() const 
    { 
        return top; 
    } 
};
