#include<iostream>
#define N 100
using namespace std;
int q[N];
int count = 1;
int n;
bool place(int i)//第i行是否有位置可以放
{
	int j=1;
	while (j < i)
	{
		if (q[i] == q[j] || abs(q[i] - q[j]) == i - j)//同列和对角线上
		{
			return false;
		}
		j++;
	}
	return true;
}
void disp()
{
	cout << "第" << ::count++ << "个解：";
	for (int i = 1; i <= n; i++)
	{
		cout << "(" << i << "," << q[i] << ")"<<" ";
	}
	cout << endl;
}
void solve(int n)
{
	int i = 1;
	q[i] = 0;
	while (i >= 0)//回溯的界限
	{
		q[i]++;//第i行，将q[i]放置在第一个位置上
		while (q[i] <= n && !place(i))
		{
			q[i]++;
		}//当第i行q[i]列不能放置时，q[i]++,试探下一列
		if (q[i] <= n)//向下分枝
		{
			if (i == n)
			{
				disp();
			}
			else
			{
				i++;
				q[i] = 0;
			}
		}
		else//如果q[i]>n,则说明在第i行找不到合适的位置，回溯到上一行为上一行重新分配下一个位置
		{
			i--;//回溯
		}
	}
}
int main()
{
	cout << "请输入n的大小：";
	cin >> n;
	cout << "n皇后问题求解如下：" << endl;
	solve(n);
}