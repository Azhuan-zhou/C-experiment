#include "utils.h"
// 传入数组A和数组长度n,对数组进行插入排序
template<typename E>
void InsSort(E A[], int n){
    int swap_times = 0;//交换次数
    int compare_times = 0;//比较次数
    cout<<"排序前的数组:";
    printHelp(A,n);
    auto start1 = std::chrono::high_resolution_clock::now();
    for(int i=1;i<n;i++){
        for(int j = i;(j>0)&&(prior<E>(A[j],A[j-1],compare_times));j--)
        {
            swap(A,j,j-1);
            swap_times++;
        }
    }
    auto stop1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(stop1 - start1);
    cout << "排序用时：" << duration1.count() << "毫秒" << std::endl;
    cout<<"插入排序的比较次数："<<compare_times<<"\n插入排序的交换次数："<<swap_times<<endl;
    cout<<"排序后的数组:";
    printHelp(A,n);
}

