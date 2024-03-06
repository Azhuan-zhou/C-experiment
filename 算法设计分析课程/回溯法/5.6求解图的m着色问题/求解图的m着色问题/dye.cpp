#include<iostream>
#define N 20
using namespace std;
int a[N][N];//邻接矩阵
int x[N];//着色方案
int n;//结点个数
int k;//边的个数
int m;//着色的颜色
int t=0;//计数器
void disp()//输出方案的解
{
	int i;
	cout << "第" << t << "个着色方案为：";
	for (i = 1; i <= n ; i++)
	{
		cout << x[i] ;
	}
	cout << endl;

}
bool same(int i)//剪枝函数，不满足时减枝
{
	for (int j = 1; j <= n; j++)
	{
		if (a[i][j] == 1 && x[i] == x[j])//结点i和结点j有边相连且他们着色相同时，返回false，剪枝
		{
			return false;
		}
	}
	return true;//否则返回true
}
void fun(int i)
{
	if (i > n)//结点个数都遍历了一遍
	{
		t++;
		disp();
	}
	else
	{
		for (int j = 1; j <= m; j++)
		{
			x[i] = j;//将结点i着第j色
			if (same(i))//满足条件时拓展结点
			{
				fun(i + 1);
			}
			x[i] = 0;//回溯
		}
	}

}
int main()
{
	int x, y;//结点
	cin >> n >> k >> m;//依次输入结点个数,边的个数,颜色的个数
	for (int i = 1; i <= k; i++)//输入
	{
		cin >> x >> y;//输入边所连接的结点
		a[x][y] = 1;
		a[y][x] = 1;
	}
	fun(1);
}