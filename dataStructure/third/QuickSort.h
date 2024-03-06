#include "utils.h"
// 找到划分的位置
template<typename E>
int partition(E A[],int low,int high,int &compare_time,int &swap_time){
    E pivot = A[high]; // 划分的元素
    int i = low; // 最低的位置
    int j = high; // 最高的位置
    while(i < j)
    {
        while(A[i] <= pivot && i<j)
        {
            compare_time++;
            i++;
        }
        compare_time++; // 结束while时候的判断
        while(A[j] >= pivot && i < j)
        {
            compare_time++;
            j--;
        }
        compare_time++;
        swap(A,i,j);
        swap_time++;
    }
    // 交换最后一个位置和partition位置
    E temp = A[i];
    A[i] = pivot;
    A[high] = temp;
    swap_time++;
    return i;
}

template<typename E>
void Sort(E A[],int low,int high,int &compare_time,int &swap_time)
{
    if(high<=low)
    {
        return;
    }
    int pivotIndex = partition(A,low,high,compare_time,swap_time);
    Sort(A,low,pivotIndex-1,compare_time,swap_time);
    Sort(A,pivotIndex+1,high,compare_time,swap_time);
}
template<typename E>
void quickSort(E A[],int n)
{
    int low = 0;
    int high = n-1;
    int swap_times = 0;//交换次数
    int compare_times = 0;//比较次数
    cout<<"排序前的数组:";
    auto start1 = std::chrono::high_resolution_clock::now();
    printHelp(A,n);
    Sort(A,low,high,compare_times,swap_times);
    auto stop1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(stop1 - start1);
    cout << "排序用时：" << duration1.count() << "毫秒" << std::endl;
    cout<<"快速排序的比较次数："<<compare_times<<"\n快速排序的交换次数："<<swap_times<<endl;
    cout<<"排序后的数组:";
    printHelp(A,n);
}
