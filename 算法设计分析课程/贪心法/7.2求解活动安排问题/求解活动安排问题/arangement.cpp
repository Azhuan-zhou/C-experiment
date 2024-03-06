#include<iostream>
#include<algorithm>
#define MAX 20
using namespace std;
struct activity
{
	int start;//��ʼʱ��
	int end;//����ʱ��
	bool operator<(const activity&A) const
	{
		return end < A.end;
	}
};
int n = 11;//�����
activity A[] = { {0},{1,4},{3,5},{0,6},{5,7},{3,8},{5,9},{6,10},{8,11},{8,12},{2,13},{12,15} };//�ʱ��
bool flag[MAX] = { 0 };
int count=0;
void solve()
{
	int i;
	int end=0;//���ڴ�����һ����ļ���ʱ��
	sort(A, A + n + 1);//���ݽ���ʱ���������
	for (i = 1; i <= n; i++)
	{
		if (A[i].start >= end)
		{
			flag[i] = true;
			end = A[i].end;
			::count++;
		}
	}
}
void disp()
{
	int i;
	cout << "�����" << endl;
	cout << "ѡȡ���";
	for (i = 1; i <= n; i++)
	{
		if (flag[i])
		{
			cout <<"�"<<i<< "[" << A[i].start << "," << A[i].end << "] ";
		}
	}
	cout << endl;
	cout << "          һ����" << ::count << "���" << endl;
}
int main()
{
	solve();
	disp();
}