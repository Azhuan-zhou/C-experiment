#include "utils.h"
template<typename E>
void Sort(E A[], E temp[], int left, int right, int &compare_times,int &swap_times) {
    if (left == right) {
        return;
    }
    int mid = (right + left) / 2; // �м�λ��
    Sort(A, temp, left, mid, compare_times,swap_times); // ���
    Sort(A, temp, mid + 1, right, compare_times,swap_times); // �ұ�

    int i1 = left; // ��벿�ֵ���ʼ����
    int i2 = mid + 1; // �Ұ벿�ֵ���ʼ����
    // ��벿�ֺ��Ұ벿�ֺϲ�Ϊһ����������
    for (int curr = left; curr <= right; ++curr) {
        if (i1 > mid)  // ��ߵ����бȽ����
        {
            temp[curr] = A[i2];
            i2++;
        }
        else if (i2 > right) // �ұ����бȽ����
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

    // ���鲢��Ľ��������ԭ���� A
    for (int i = left; i <= right; ++i) {
        A[i] = temp[i];
    }
}


template<typename E>
void mergeSort(E A[],int n){
    auto start1 = std::chrono::high_resolution_clock::now();
    int compare_times = 0;
    int swap_times = 0;//��������
    int left = 0;
    int right = n-1;
    E temp[n];
    cout<<"����ǰ������:";
    printHelp<E>(A,n);
    Sort<E>(A,temp,left,right,compare_times,swap_times);
    auto stop1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(stop1 - start1);
    cout << "������ʱ��" << duration1.count() << "����" << std::endl;
    cout<<"�鲢����ıȽϴ�����"<<compare_times<<"\n�鲢����Ľ���������"<<swap_times<<endl;
    cout<<"����������:";
    printHelp<E>(A,n);
}