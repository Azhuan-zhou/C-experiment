#include "utils.h"
using namespace std;

// ��ȡ���� num �ĵ� digit λ���ӵ�λ����λ��
int getDigit(int num, int digit) {
    for (int i = 0; i < digit; i++) {
        num /= 10;
    }
    return num % 10;
}

// ��������
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

// ��������
template<typename E>
void radixSort(E A[], int n) {
    cout << "����ǰ������:";
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
    cout << "������ʱ��" << duration1.count() << "����" << std::endl;
    cout<<"�����ıȽϴ�����"<<compare_count<<"\n��������Ľ���������"<<swap_count<<endl;
    cout << "����������:";
    printHelp(A, n);
}
