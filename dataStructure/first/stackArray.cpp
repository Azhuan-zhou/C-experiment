#include <iostream>
#define defaultSize 100
using namespace std;

// ˳��ջ
template <typename E>
class AStack
{
private:
    int maxSize; // ջ�����Ԫ��
    int top; // ջ��λ������,�Ǵ���ջԪ�ص�λ��
    E *listArray; // ջ
public:
    // ջ�Ĺ���
    AStack(int size =defaultSize) 
    { 
        maxSize = size; 
        top = 0; 
        listArray = new E[size]; 
    }
    // ջ������
    ~AStack() 
    { 
        delete [] listArray; 
    } 
    // ���ջ��Ԫ��
    void clear() 
    { 
        top = 0; 
    }
    // it��ջ 
    void push(const E& it) 
    {
        if(top == maxSize)
        {
            cout<<"Stack is full";
            exit(-1);
        }
        listArray[top++] = it;
    }
    // ��ջ
    E pop() 
    { 
        if(top==0)
        {
            cout<<"Stack is empty";
            exit(-1);
        }
        return listArray[--top];
    }
    // ��ȡջ��Ԫ��
    const E& topValue() const 
    { 
        if(top==0)
        {
            cout<<"Stack is empty";
            exit(-1);
        }
        return listArray[top-1];
    }
    // ��ȡջ�ĳ���
    int length() const 
    { 
        return top; 
    } 
};
