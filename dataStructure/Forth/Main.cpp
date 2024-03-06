#include "SSearch.h"
#include "BSearch.h"
//顺序查找
int main() {
    srand(time(0)); // 初始化随机数生成器

    const int arraySize = 100;
    int arr[arraySize];

    generateRandomArray(arr, arraySize);

    // 最好情况：目标元素在数组的开头
    int targetBestCase = arr[0];
    int comparisonsBestCase;
    int positionBestCase = sequentialSearch(arr, arraySize, targetBestCase, comparisonsBestCase);

    // 最坏情况：目标元素在数组的末尾或不存在
    int targetWorstCase = 101; // 假设不存在的元素
    int comparisonsWorstCase;
    int positionWorstCase = sequentialSearch(arr, arraySize, targetWorstCase, comparisonsWorstCase);

    // 平均情况：目标元素等概率分布在数组中
    int targetAverageCase = arr[rand() % arraySize]; // 随机选择一个元素作为目标
    int comparisonsAverageCase;
    int positionAverageCase = sequentialSearch(arr, arraySize, targetAverageCase, comparisonsAverageCase);

    // 输出结果
    cout << "Best Case:" << endl;
    cout << "Target: " << targetBestCase << ", Position: " << positionBestCase << ", Comparisons: " << comparisonsBestCase << endl;

    cout << "\nWorst Case:" << endl;
    cout << "Target: " << targetWorstCase << ", Position: " << positionWorstCase << ", Comparisons: " << comparisonsWorstCase << endl;

    cout << "\nAverage Case:" << endl;
    cout << "Target: " << targetAverageCase << ", Position: " << positionAverageCase << ", Comparisons: " << comparisonsAverageCase << endl;

    return 0;
}

//// 二分查找
int main() {
    srand(time(0)); // 初始化随机数生成器
    const int arraySize = 100;
    int arr[arraySize];
    generateSortedArray(arr, arraySize);
    // 最好情况：目标元素在数组的中间
    int targetBestCase = arr[(arraySize-1) / 2];
    int comparisonsBestCase;
    int positionBestCase = binarySearch(arr, arraySize, targetBestCase, comparisonsBestCase);
    // 最坏情况：目标元素在数组的两端或不存在
    int targetWorstCase1 = -1; // 不存在的元素
    int comparisonsWorstCase1;
    int positionWorstCase1 = binarySearch(arr, arraySize, targetWorstCase1, comparisonsWorstCase1);
    // 在数组的最后一个元素之后
    int targetWorstCase2 = arraySize;
    int comparisonsWorstCase2;
    int positionWorstCase2 = binarySearch(arr, arraySize, targetWorstCase2, comparisonsWorstCase2);
    // 平均情况：目标元素等概率分布在数组中
    int targetAverageCase = arr[rand() % arraySize]; // 随机选择一个元素作为目标
    int comparisonsAverageCase;
    int positionAverageCase = binarySearch(arr, arraySize, targetAverageCase, comparisonsAverageCase);

    // 输出结果
    cout << "Best Case:" << endl;
    cout << "Target: " << targetBestCase << ", Position: " << positionBestCase << ", Comparisons: " << comparisonsBestCase << endl;

    cout << "\nWorst Case 1:" << endl;
    cout << "Target: " << targetWorstCase1 << ", Position: " << positionWorstCase1 << ", Comparisons: " << comparisonsWorstCase1 << endl;

    cout << "\nWorst Case 2:" << endl;
    cout << "Target: " << targetWorstCase2 << ", Position: " << positionWorstCase2 << ", Comparisons: " << comparisonsWorstCase2 << endl;

    cout << "\nAverage Case:" << endl;
    cout << "Target: " << targetAverageCase << ", Position: " << positionAverageCase << ", Comparisons: " << comparisonsAverageCase << endl;

    return 0;
}

