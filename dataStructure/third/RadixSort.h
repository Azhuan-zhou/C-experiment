#include "utils.h"
using namespace std;

// 获取数字 num 的第 digit 位（从低位到高位）
int getDigit(int num, int digit) {
    for (int i = 0; i < digit; i++) {
        num /= 10;
    }
    return num % 10;
}

// 计数排序
template<typename E>
void countingSort(E A[], int n, int digit, int &compare_count, int &swap_count) {
    const int base = 10;
    int output[n];
    int count[base] = {0};
    for (int i = 0; i < n; i++) {
        count[getDigit(A[i], digit)]++;
    }
    for (int i = 1; i < base; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[getDigit(A[i], digit)] - 1] = A[i];
        count[getDigit(A[i], digit)]--;
        swap_count++;
    }
    for (int i = 0; i < n; i++) {
        A[i] = output[i];
    }
}

// 基数排序
template<typename E>
void radixSort(E A[], int n) {
    cout << "排序前的数组:";
    printHelp(A, n);
    auto start1 = std::chrono::high_resolution_clock::now();
    int maxNum = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > maxNum) {
            maxNum = A[i];
        }
    }

    int digitCount = 0;
    while (maxNum > 0) {
        digitCount++;
        maxNum /= 10;
    }

    int compare_count = 0;
    int swap_count = 0;

    for (int digit = 0; digit < digitCount; digit++) {
        countingSort(A, n, digit, compare_count, swap_count);
    }
    auto stop1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(stop1 - start1);
    cout << "排序用时：" << duration1.count() << "毫秒" << std::endl;
    cout<<"基数的比较次数："<<compare_count<<"\n基数排序的交换次数："<<swap_count<<endl;
    cout << "排序后的数组:";
    printHelp(A, n);
}
