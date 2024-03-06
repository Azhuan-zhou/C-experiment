#include <iostream>
#include "stackArray.cpp"
#define defaultSize 100
using namespace std;

template <typename E> 
class AQueue
{
private:
    int maxSize; //???е?????
    int front; // ?????????????
    int rear; // ??????????????
    E *listArray; // ????
public:
    // ???е?????????λ?ò????????rear
    AQueue(int size =defaultSize) 
    { 
        maxSize = size+1;
        rear = 0; 
        front = 1;
        listArray = new E[maxSize];
    }
    // ???е?????
    ~AQueue() 
    { delete [] listArray; 
    } 
    // ?????????е????
    void clear() 
    { 
        rear = 0; 
        front = 1; 
    } 
    // it???
    void enqueue(const E& it) 
    { 
        if(((rear+2) % maxSize)== front)
        {
            cout<<"Queue is full";
            exit(-1);
        }
        rear = (rear+1) % maxSize; // ??β???????????????
        listArray[rear] = it;
    }
    // ????
    E dequeue() 
    { 
        if (length() == 0)
        {
            cout<<"Queue is empty";
            exit(-1);
        }
        E it = listArray[front]; // ???????
        front = (front+1) % maxSize; 
        return it;
    }
    // ???????
    const E& frontValue() const 
    { 
        if (length() == 0)
        {
            cout<<"Queue is empty";
            exit(-1);
        }
        return listArray[front];
    }
    // ??????е????
    int length() const
    { 
        return ((rear+maxSize) - front + 1) % maxSize; 
    }
};
