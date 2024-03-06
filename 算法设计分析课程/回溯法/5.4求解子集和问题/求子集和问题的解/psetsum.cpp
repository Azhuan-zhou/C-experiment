#include<iostream>
#define N 4
using namespace std;
int w[] = { 11,13,24,7 };
int W = 31;
int c = 0;
void disp(int x[])//输出
{
	cout << "第"<<c<<"个解选取的数为：";
	for (int i = 0; i < N; i++)
	{
		if (x[i] == 1)
		{
			cout << w[i] << " ";
		}
	}
	cout << endl;
}
void fun(int i, int tw, int rw, int op[])
{
	if (i == N)//遍历完所有的元素
	{
		if (tw == W)//当数的总和等于要求的子集和时
		{
			c++;//解的个数加一
			disp(op);
		}
	}
	else
	{
		//左枝：选择第i个数
		if (tw + w[i] <= W)
		{
			op[i] = 1;
			fun(i + 1, tw + w[i], rw - w[i], op);
		}
		//右枝：不选择第i个数
		if (tw + rw - w[i]>=W)
		{
			op[i] = 0;
			fun(i + 1, tw, rw - w[i], op);
		}
	}
}
int sum(int a[])//求和
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += a[i];
	}
	return sum;
}
int main()
{
	int op[N];
	fun(0, 0, sum(w), op);
}