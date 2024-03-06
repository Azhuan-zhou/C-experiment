#include "utils.h"
template<typename E>
void InsSort2(E A[],int n,int incr,int &compare_time,int &swap_time){
    // ��incrΪ�����Ĳ�������
    for (int i = incr; i < n; i+=incr) {
        for(int j=i;(j>=incr&&(prior(A[j],A[j-incr],compare_time)));j-=incr){
            swap(A,j,j-incr);
            swap_time++;
        }
    }
}

template<typename E>
void shellSort(E A[],int n){
    int swap_times = 0;//��������
    int compare_times = 0;//�Ƚϴ���
    cout<<"����ǰ������:";
    printHelp<E>(A,n);
    auto start1 = std::chrono::high_resolution_clock::now();
    for(int i=n/2;i>2;i/=2)
    {
        for(int j=0;j<i;j++)
        {
            InsSort2<E>(A,n-j,i,compare_times,swap_times);
        }
    }
    InsSort2<E>(A,n,1,compare_times,swap_times);
    auto stop1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(stop1 - start1);
    cout << "������ʱ��" << duration1.count() << "����" << std::endl;
    cout<<"ϣ������ıȽϴ�����"<<compare_times<<"\nϣ������Ľ���������"<<swap_times<<endl;
    cout<<"����������:";
    printHelp<E>(A,n);
}