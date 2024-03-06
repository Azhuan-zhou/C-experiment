#include<iostream>
#include<algorithm>
#define N 20
using namespace std;
int a[N];
int n;
int maxn;
int bestd;
void solve()
{
	sort(a, a + n);
	maxn = 1;
	bestd = a[0];
	int pred;//储存当前的最长连续子序列的值
	int num=0;//储存当前的最长连续子序列的值
	int i=0;//从第一个元素开始
	while (i < n)
	{
		pred = a[i];
		//计算当前连续元素的个数
		while (i<n && pred == a[i])//a[i-1]和a[i]不连续时退出
		{
			i++;
			num++;
		}
		if (num > maxn)
		{
			maxn = num;
			bestd = pred;
		}
		num = 0;//置零
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "求解过程：" << endl;
	solve();
	cout << "出现次数最多的元素为：" << bestd << ",其个数为：" << maxn << endl;
}
