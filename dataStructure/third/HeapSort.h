#include "Heap.h"
#include "utils.h"

template <typename E>
void heapSort(E A[], int n) {
    cout<<"排序前的数组:";
    printHelp(A,n);
    auto start1 = std::chrono::high_resolution_clock::now();
    MinHeap<E> heap(n);
    for (int i = 0; i < n; i++) {
        heap.push(A[i]);
    }
    heap.buildHeap(); // 创建最小堆
    for (int i = 0; i<n; i++) {
        A[i] = heap.pop();
    }
    auto stop1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(stop1 - start1);
    cout << "排序用时：" << duration1.count() << "毫秒" << std::endl;
    cout<<"堆排序的比较次数："<<heap.getCompareCount()<<"\n堆排序的交换次数："<<heap.getSwapCount()<<endl;
    cout<<"排序后的数组:";
    printHelp(A,n);
}