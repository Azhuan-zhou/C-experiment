#include <iostream>
using namespace std;

template <typename E>
class MinHeap {
private:
    E* heap;
    int capacity;
    int size;
    int compare_count; // 记录比较次数
    int swap_count;   // 记录交换次数

    void heapify(int n, int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        compare_count++; // 比较次数加1
        if (left < n && heap[left] < heap[smallest]) {
            smallest = left;
        }
        compare_count++; // 比较次数加1
        if (right < n && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != i) {
            std::swap(heap[i], heap[smallest]);
            swap_count++; // 交换次数加1
            heapify(n, smallest);
        }
    }

public:
    MinHeap(int capacity) : capacity(capacity), size(0), compare_count(0), swap_count(0) {
        heap = new E[capacity];
    }

    ~MinHeap() {
        delete[] heap;
    }

    void push(E element) {
        if (size >= capacity) {
            throw std::runtime_error("Heap is full");
        }

        heap[size] = element;
        int i = size;
        size++;

        while (i > 0) {
            int parent = (i - 1) / 2;
            compare_count++; // 比较次数加1
            if (heap[parent] <= heap[i]) {
                break;
            }
            std::swap(heap[i], heap[parent]);
            swap_count++; // 交换次数加1
            i = parent;
        }
    }

    void buildHeap() {
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(size, i);
        }
    }

    E pop() {
        if (size <= 0) {
            throw std::runtime_error("Heap is empty");
        }

        E root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapify(size, 0);
        swap_count++; // 交换次数加1
        return root;
    }

    bool empty() {
        return size == 0;
    }

    int getCompareCount() {
        return compare_count;
    }

    int getSwapCount() {
        return swap_count;
    }
};