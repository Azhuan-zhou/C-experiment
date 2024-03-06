#include<iostream>
#define N 4
using namespace std;
int W[N][N] = { {9,2,7,8},{6,4,3,7},{5,8,1,8},{7,6,9,4} };
int a[N];//最优任务分配
int mincost = 10000;
void swap(int* a, int* b)//交换位置
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void disp()
{
	cout << "最优方案：" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "第" << i+1 << "个人安排任务" << a[i]<<endl;
	}
	cout << "总成本：" << mincost;
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