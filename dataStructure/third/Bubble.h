#include "utils.h"
template<typename E>
void bubble(E A[],int n){
    int swap_times = 0;//��������
    int compare_times = 0;//�Ƚϴ���
    cout<<"����ǰ������:";
    printHelp(A,n);
    auto start1 = std::chrono::high_resolution_clock::now();
    for(int i=0;i<n-1;i++)
    {
        for(int j=n-1;j>i;j--) {
            if (prior(A[j], A[j - 1], compare_times)) {
                swap(A[j], A[j - 1]);
                swap_times++;
            }
        }
    }
    auto stop1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(stop1 - start1);
    cout << "������ʱ��" << duration1.count() << "����" << std::endl;
    cout<<"ð������ıȽϴ�����"<<compare_times<<"\nð������Ľ���������"<<swap_times<<endl;
    cout<<"����������:";
    printHelp(A,n);
}