#include<iostream>
#include<algorithm>
#define N 100
using namespace std;
int n=4;//加工工件个数
int a[N] = { 5,12,4,8 };//第一个机器加工物品的时间
int b[N] = { 6,2,14,7 };//第二个机器加工物品的时间
struct nodetype
{
	int no;//加工序号
	int time;//a,b最小时间
	bool group;//分组，1代表N1组，0代表N2组
	bool operator<(const nodetype& e)const
	{
		return time < e.time;
	}

};
int best[N];//存放最优调度序列
int max(int &a,int& b)//比较大小
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
void solve()
{
	int i, j, k;
	//为结点赋值
	nodetype c[N];
	for (i = 0; i < n; i++)
	{
		c[i].no = i + 1;
		c[i].group = (a[i] < b[i]);
		c[i].time = a[i] < b[i] ? a[i] : b[i];
	}
	sort(c, c + n);
	j = 0;
	k = n - 1;
	for (i = 0; i < n; i++)
	{
		if (c[i].group == 1)
		{
			best[j++] = c[i].no;
		}
		else
		{
			best[k--] = c[i].no;
		}
	}
}
int time()
{
	int f1=0;
	int f2=0;
	for (int i = 0; i < n; i++)
	{
		f1 += a[best[i]-1];
		f2 =max(f2, f1) + b[best[i]-1];
	}
	return f2;
}
int main()
{
	cout << "求解结果" << endl;
	solve();
	cout << "总时间：" << time() << endl;
	cout << "调度方案：";
	for (int i = 0; i < n; i++)
	{
		cout << best[i];
	}
	cout << endl;
}