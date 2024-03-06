#include<iostream>
#include<algorithm>
#define MAX 20
using namespace std;
struct animal
{
	int no;//ţ�ı��
	int start;//��ʼʱ��
	int end;//����ʱ��
	bool operator<(const animal& A) const
	{
		if (end == A.end)
		{
			return start <= A.start;
		}
		else
		{
			return end <= A.end;
		}
	}
};
int n = 5;//ţ�ĸ���
animal A[] = { {0},{1,1,10},{2,2,4},{3,3,6},{4,5,8},{5,4,7} };//�ʱ�䣬
int Fence[MAX] = { 0 };//Fence[i]=num,��ʾ��i��������ڵ�num������
int num = 1;//�������
void solve()
{
	int i;
	int end = 0;//���ڴ�����һ�����̵Ľ���ʱ��
	sort(A, A + n + 1);//���ݽ���ʱ���������
	for (i = 1; i <= n; i++)
	{
		if (Fence[i] == 0)
		{
			Fence[i] = ::num;
			end = A[i].end;
			for (int j = i+1; j <= n; j++)
			{
				if (Fence[j] == 0 && A[j].start>end)
				{
					Fence[j] = ::num;
					end = A[j].end;
				}
			}
			::num++;
		}
	}
}
void disp()
{
	int i;
	cout << "�����" << endl;
	for (i = 1; i <= n; i++)
	{
		cout << "ţ" << A[i].no << "���ŵ�������" << Fence[i]<<endl;
	}
}
int main()
{
	solve();
	disp();
}