#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
// 二分检索算法
int binarySearch(const int arr[], int size, int target, int& comparisons) {
    int low = 0;
    int high = size - 1;
    comparisons = 0;

    while (low <= high) {
        comparisons++; // 记录比较次数
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid; // 返回找到的位置
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // 如果未找到，返回-1
}
// 生成有序数组
void generateSortedArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = i; // 生成有序数组
    }
}