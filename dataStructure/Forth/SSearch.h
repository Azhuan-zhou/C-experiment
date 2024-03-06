#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// 顺序检索算法
int sequentialSearch(const int arr[], int size, int target, int& comparisons) {
    comparisons = 0;
    for (int i = 0; i < size; ++i) {
        comparisons++; // 记录比较次数
        if (arr[i] == target) {
            return i; // 返回找到的位置
        }
    }
    return -1; // 如果未找到，返回-1
}

// 生成随机数组
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100; // 生成0到99的随机数
    }
}
