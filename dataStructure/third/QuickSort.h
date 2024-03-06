#include "utils.h"
// �ҵ����ֵ�λ��
template<typename E>
int partition(E A[],int low,int high,int &compare_time,int &swap_time){
    E pivot = A[high]; // ���ֵ�Ԫ��
    int i = low; // ��͵�λ��
    int j = high; // ��ߵ�λ��
    while(i < j)
    {
        while(A[i] <= pivot && i<j)
        {
            compare_time++;
            i++;
        }
        compare_time++; // ����whileʱ����ж�
        while(A[j] >= pivot && i < j)
        {
            compare_time++;
            j--;
        }
        compare_time++;
        swap(A,i,j);
        swap_time++;
    }
    // �������һ��λ�ú�partitionλ��
    E temp = A[i];
    A[i] = pivot;
    A[high] = temp;
    swap_time++;
    return i;
}

template<typename E>
void Sort(E A[],int low,int high,int &compare_time,int &swap_time)
{
    if(high<=low)
    {
        return;
    }
    int pivotIndex = partition(A,low,high,compare_time,swap_time);
    Sort(A,low,pivotIndex-1,compare_time,swap_time);
    Sort(A,pivotIndex+1,high,compare_time,swap_time);
}
template<typename E>
void quickSort(E A[],int n)
{
    int low = 0;
    int high = n-1;
    int swap_times = 0;//��������
    int compare_times = 0;//�Ƚϴ���
    cout<<"����ǰ������:";
    auto start1 = std::chrono::high_resolution_clock::now();
    printHelp(A,n);
    Sort(A,low,high,compare_times,swap_times);
    auto stop1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(stop1 - start1);
    cout << "������ʱ��" << duration1.count() << "����" << std::endl;
    cout<<"��������ıȽϴ�����"<<compare_times<<"\n��������Ľ���������"<<swap_times<<endl;
    cout<<"����������:";
    printHelp(A,n);
}
