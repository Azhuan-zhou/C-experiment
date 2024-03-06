#include "utils.h"
template<typename E>
void selSort(E A[], int n){
    int swap_times = 0;//��������
    int compare_times = 0;//�Ƚϴ���
    cout<<"����ǰ������:";
    printHelp(A,n);
    int lowIndex;
    auto start1 = std::chrono::high_resolution_clock::now();
    for(int i=0;i<n;i++)
    {
        lowIndex = i;
        for(int j=n-1;j>i;j--)
        {
            if(prior<E>(A[j],A[lowIndex],compare_times))
            {
                lowIndex = j;
            }
        }
        swap(A,i,lowIndex);
        swap_times++;
    }
    auto stop1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(stop1 - start1);
    cout << "������ʱ��" << duration1.count() << "����" << std::endl;
    cout<<"ѡ������ıȽϴ�����"<<compare_times<<"\nѡ������Ľ���������"<<swap_times<<endl;
    cout<<"����������:";
    printHelp(A,n);
}
