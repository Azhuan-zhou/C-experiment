#include <iostream>
#define defaultSize 100
using namespace std;

template <typename E>
class AQueue
{
private:
    int maxSize;
    int Front;
    int rear;
    E *listArray;
public:
    AQueue(int size =defaultSize)
    {
        maxSize = size+1;
        rear = 0;
        Front = 1;
        listArray = new E[maxSize];
    }
    ~AQueue()
    { delete [] listArray;
    }
    void clear()
    {
        rear = 0;
        Front = 1;
    }
    void enqueue(const E& it)
    {
        if(((rear+2) % maxSize)== Front)
        {
            cout<<"Queue is full";
            exit(-1);
        }
        rear = (rear+1) % maxSize;
        listArray[rear] = it;
    }
    E dequeue()
    {
        if (length() == 0)
        {
            cout<<"Queue is empty";
            exit(-1);
        }
        E it = listArray[Front];
        Front = (Front+1) % maxSize;
        return it;
    }
    const E& frontValue() const
    {
        if (length() == 0)
        {
            cout<<"Queue is empty";
            exit(-1);
        }
        return listArray[Front];
    }
    int length() const
    {
        return ((rear+maxSize) - Front + 1) % maxSize;
    }
    bool empty(){
        if (length() == 0)
        {
            return true;
        }
        return false;
    }

};
