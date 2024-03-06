#include<iostream>
#include<algorithm>
#define MAX 20
using namespace std;
struct interval
{
	int a;//第一个数
	int b;//第二个数
	bool operator<(const interval& I)const
	{
		if (b == I.b)
		{
			return a < I.a;
		}
		else
		{
			return b < I.b;
		}
	}
};
interval I[MAX];
int num = 0;
void solve(int n)
{
	int i;
	for (i = 0; i < n; i++)//检查输入区间是否符合要求，如果不符合则修改
	{
		if (I[i].a > I[i].b)
		{
			int t = I[i].a;
			I[i].a = I[i].b;
			I[i].b = t;
		}
	}
	sort(I, I + n + 1);
	int end = 0;
	for (int j = 0; j < n; j++)
	{
		if (I[j].a >= end)
		{
			end = I[i].b;
			num++;
		}
	}
}
void disp(int n)
{
	cout << "去掉最少闭区间的个数为:" << n-num;
}
int main()
{
	int n;//区间个数
	int i;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> I[i].a >> I[i].b;
	}
	solve(n);
	disp(n);
	
}