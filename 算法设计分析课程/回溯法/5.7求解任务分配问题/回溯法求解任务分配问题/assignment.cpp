#include<iostream>
#define N 4
using namespace std;
int W[N][N] = { {9,2,7,8},{6,4,3,7},{5,8,1,8},{7,6,9,4} };
int a[N];//�����������
int mincost = 10000;
void swap(int* a, int* b)//����λ��
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void disp()
{
	cout << "���ŷ�����" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "��" << i+1 << "���˰�������" << a[i]<<endl;
	}
	cout << "�ܳɱ���" << mincost;
}
void fun(int i,int A[])
{
	if (i == N)
	{
		int sum=0;
		for (int m = 0; m < N; m++)
		{
			sum += W[m][A[m]-1];
		}
		if (sum <= mincost)
		{
			mincost = sum;
			for (int n = 0; n < N; n++)
			{
				a[n] = A[n];
			}
		}
	}
	else
	{
		for (int j = i; j < N; j++)
		{
			swap(&A[i], &A[j]);
			fun(i + 1,A);
			swap(&A[i], &A[j]);
		}
	}
}
int main()
{
	int A[N] = { 1,2,3,4 };
	fun(0, A);
	disp();
}