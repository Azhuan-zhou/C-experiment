#include "utils.h"
template<typename E>
void Sort(E A[], E temp[], int left, int right, int &compare_times,int &swap_times) {
    if (left == right) {
        return;
    }
    int mid = (right + left) / 2; // 中间位置
    Sort(A, temp, left, mid, compare_times,swap_times); // 左边
    Sort(A, temp, mid + 1, right, compare_times,swap_times); // 右边

    int i1 = left; // 左半部分的起始索引
    int i2 = mid + 1; // 右半部分的起始索引
    // 左半部分和右半部分合并为一个有序数组
    for (int curr = left; curr <= right; ++curr) {
        if (i1 > mid)  // 左边的序列比较完毕
        {
            temp[curr] = A[i2];
            i2++;
        }
        else if (i2 > right) // 右边序列比较完毕
        {
            temp[curr] = A[i1++];
        } else if (prior(A[i1], A[i2], compare_times)) {
            temp[curr] = A[i1++];
        }
        else
        {
            swap_times++;
            temp[curr] = A[i2++];
        }
    }

    // 将归并后的结果拷贝回原数组 A
    for (int i = left; i <= right; ++i) {
        A[i] = temp[i];
    }
}


template<typename E>
void mergeSort(E A[],int n){
    auto start1 = std::chrono::high_resolution_clock::now();
    int compare_times = 0;
    int swap_times = 0;//交换次数
    int left = 0;
    int right = n-1;
    E temp[n];
    cout<<"排序前的数组:";
    printHelp<E>(A,n);
    Sort<E>(A,temp,left,right,compare_times,swap_times);
    auto stop1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(stop1 - start1);
    cout << "排序用时：" << duration1.count() << "毫秒" << std::endl;
    cout<<"归并排序的比较次数："<<compare_times<<"\n归并排序的交换次数："<<swap_times<<endl;
    cout<<"排序后的数组:";
    printHelp<E>(A,n);
}