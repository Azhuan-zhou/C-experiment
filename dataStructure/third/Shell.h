#include "utils.h"
template<typename E>
void InsSort2(E A[],int n,int incr,int &compare_time,int &swap_time){
    // 以incr为增量的插入排序
    for (int i = incr; i < n; i+=incr) {
        for(int j=i;(j>=incr&&(prior(A[j],A[j-incr],compare_time)));j-=incr){
            swap(A,j,j-incr);
            swap_time++;
        }
    }
}

template<typename E>
void shellSort(E A[],int n){
    int swap_times = 0;//交换次数
    int compare_times = 0;//比较次数
    cout<<"排序前的数组:";
    printHelp<E>(A,n);
    auto start1 = std::chrono::high_resolution_clock::now();
    for(int i=n/2;i>2;i/=2)
    {
        for(int j=0;j<i;j++)
        {
            InsSort2<E>(A,n-j,i,compare_times,swap_times);
        }
    }
    InsSort2<E>(A,n,1,compare_times,swap_times);
    auto stop1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(stop1 - start1);
    cout << "排序用时：" << duration1.count() << "毫秒" << std::endl;
    cout<<"希尔排序的比较次数："<<compare_times<<"\n希尔排序的交换次数："<<swap_times<<endl;
    cout<<"排序后的数组:";
    printHelp<E>(A,n);
}