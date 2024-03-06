#include <iostream>
#define defaultSize 100
using namespace std;


template <typename E> 
class AList 
{
private:
    int maxSize;  // 顺序表最大长度
    int listSize;  // 当前顺序表的长度
    int curr;  // 当前位置
    E* listArray; // 顺序表
public:
    // 顺序表构造函数
    AList(int size=defaultSize) 
    {
        maxSize = size;
        listSize = curr = 0;
        listArray = new E[maxSize];
    }
    // 顺序表析构函数
    ~AList() { delete [] listArray; } 
    // 清空顺序表元素
    void clear() 
    { 
        delete [] listArray; 
        listSize = curr = 0; 
        listArray = new E[maxSize]; 
    }
    // 在cur位置插入it元素
    void insert(const E& it) 
    {
        if(listSize >= maxSize)
        {
            cout<<"List capacity exceeded";
        } 
        for(int i=listSize; i>curr; i--) 
            listArray[i] = listArray[i-1];
        listArray[curr] = it;
        listSize++; 
    }   
    // 在顺序表的最后的位置添加元素it
    void append(const E& it)
    { 
        if (listSize >= maxSize)
        {
            cout<<"List capacity exceeded";
            exit(-1);
        }
        listArray[listSize++] = it;
    }
    // 将cur位置的元素移除并返回
    E remove() 
    {
        if (curr<0 && curr >= listSize)
        {
            cout<<"No element";
            exit(-1);
        }
        E it = listArray[curr]; 
        for(int i=curr; i<listSize-1; i++) 
            listArray[i] = listArray[i+1];
        listSize--; 
        return it;
    }
    // 将cur移动到顺序表的表首
    void moveToStart() { curr = 0; } 
    // 将cur移动到顺序表的表尾
    void moveToEnd() { curr = listSize; } 
    // 将cur向前移动一个
    void prev() { if (curr != 0) curr--; } 
    // 将cur向后移动一个
    void next() { if (curr < listSize) curr++; } 
    // 获取顺序表的表长
    int length() const { return listSize; }
    // 获取当前cur位置
    int currPos() const { return curr; }
    // 将cur移动到指定位置pos
    void moveToPos(int pos) 
    {
        if (pos<0 && pos>listSize)
        {
            cout<<"Pos out of range";
            exit(-1);
        }
        curr = pos;
    }
    // 获取cur位置的元素
    const E& getValue() const 
    { 
        if(curr<0 && curr>listSize)
        {
            cout<<"No current element";
            exit(-1);
        }
        return listArray[curr];
    }
};

