#include "utils.h"
// ��������A�����鳤��n,��������в�������
template<typename E>
void InsSort(E A[], int n){
    int swap_times = 0;//��������
    int compare_times = 0;//�Ƚϴ���
    cout<<"����ǰ������:";
    printHelp(A,n);
    auto start1 = std::chrono::high_resolution_clock::now();
    for(int i=1;i<n;i++){
        for(int j = i;(j>0)&&(prior<E>(A[j],A[j-1],compare_times));j--)
        {
            swap(A,j,j-1);
            swap_times++;
        }
    }
    auto stop1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(stop1 - start1);
    cout << "������ʱ��" << duration1.count() << "����" << std::endl;
    cout<<"��������ıȽϴ�����"<<compare_times<<"\n��������Ľ���������"<<swap_times<<endl;
    cout<<"����������:";
    printHelp(A,n);
}

