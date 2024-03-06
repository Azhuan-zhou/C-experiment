#include "Heap.h"
#include "utils.h"

template <typename E>
void heapSort(E A[], int n) {
    cout<<"����ǰ������:";
    printHelp(A,n);
    auto start1 = std::chrono::high_resolution_clock::now();
    MinHeap<E> heap(n);
    for (int i = 0; i < n; i++) {
        heap.push(A[i]);
    }
    heap.buildHeap(); // ������С��
    for (int i = 0; i<n; i++) {
        A[i] = heap.pop();
    }
    auto stop1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(stop1 - start1);
    cout << "������ʱ��" << duration1.count() << "����" << std::endl;
    cout<<"������ıȽϴ�����"<<heap.getCompareCount()<<"\n������Ľ���������"<<heap.getSwapCount()<<endl;
    cout<<"����������:";
    printHelp(A,n);
}