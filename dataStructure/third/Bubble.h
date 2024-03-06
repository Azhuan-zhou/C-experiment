#include "utils.h"
template<typename E>
void bubble(E A[],int n){
    int swap_times = 0;//交换次数
    int compare_times = 0;//比较次数
    cout<<"排序前的数组:";
    printHelp(A,n);
    auto start1 = std::chrono::high_resolution_clock::now();
    for(int i=0;i<n-1;i++)
    {
        for(int j=n-1;j>i;j--) {
            if (prior(A[j], A[j - 1], compare_times)) {
                swap(A[j], A[j - 1]);
                swap_times++;
            }
        }
    }
    auto stop1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(stop1 - start1);
    cout << "排序用时：" << duration1.count() << "毫秒" << std::endl;
    cout<<"冒泡排序的比较次数："<<compare_times<<"\n冒泡排序的交换次数："<<swap_times<<endl;
    cout<<"排序后的数组:";
    printHelp(A,n);
}