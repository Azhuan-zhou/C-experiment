#include<iostream>
#define N 4
using namespace std;
int w[] = { 11,13,24,7 };
void fun(int i, int tw, int rw,int W,int &count)
{
	if (i == N)//遍历完所有的元素
	{
		if (tw == W)//当数的总和等于要求的子集和时
		{
			count++;//解的个数加一
		}
	}
	else
	{
		//左枝：选择第i个数
		if (tw + w[i] <= W)
		{
			fun(i + 1, tw + w[i], rw - w[i],W,count);
		}
		//右枝：不选择第i个数
		if (tw + rw - w[i] >= W)
		{
			fun(i + 1, tw, rw - w[i],W,count);
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
bool solve(int W)//判断当子集和为W时是否存在解
{
	int Sum=sum(w);
	int count = 0;
	fun(0, 0, Sum, W, count);
	if (count > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int W;
	W = 7;
	//W = 7
	cout << "W=" << W << "时，";
	if (solve(W))
	{
		cout << "存在解"<<endl;
	}
	else
	{
		cout << "没有解"<<endl;
	}
	W = 15;
	//W = 15
	cout << "W=" << W << "时，";
	if (solve(W))
	{
		cout << "存在解" << endl;
	}
	else
	{
		cout << "没有解" << endl;
	}
	W = 21;
	//W=21
	cout << "W=" << W << "时，";
	if (solve(W))
	{
		cout << "存在解" << endl;
	}
	else
	{
		cout << "没有解" << endl;
	}
	W = 24;
	//W = 24
	cout << "W=" << W << "时，";
	if (solve(W))
	{
		cout << "存在解" << endl;
	}
	else
	{
		cout << "没有解" << endl;
	}
}