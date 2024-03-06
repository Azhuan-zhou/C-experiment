#include<iostream>
#include<vector>
#define N 20
using namespace std;
int dp[N][N];//用于存放最短路径
int pre[N][N];//用于存放前驱数字的列号
int a[N][N];
int n;
int minpath;
int minj;
void Search()
{
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)//边界
	{
		dp[i][1] = dp[i - 1][1]+a[i][1];
		pre[i][1] = 1;
	}
	for (int i = 1; i <= n; i++)//对角线上
	{
		dp[i][i] = dp[i - 1][i - 1]+a[i][i];
		pre[i][i] = i - 1;
	}
	for (int i = 3; i <= n; i++)//中间位置
	{
		for (int j = 2; j < i; j++)
		{
			if (dp[i - 1][j - 1] < dp[i - 1][j])
			{
				pre[i][j] = j - 1;
				dp[i][j] = dp[i - 1][j - 1] + a[i][j];
			}
			else
			{
				pre[i][j] = j ;
				dp[i][j] = dp[i-1][j] + a[i][j];
			}
		}
	}
	minpath = dp[n][1];
	cout << dp[n][1] << endl;
	for (int j = 2; j <= n; j++)
	{
		cout << dp[n][j] << endl;
		if (dp[n][j] < minpath)
		{
			minpath = dp[n][j];
			minj = j;
		}
	}

}
void disp()//输出
{
	int i = n;
	vector<int> path;
	cout << "最短路径长度为：" << dp[n][minj] << endl;
	while (i >= 1)//先将最优的路径存放到动态数组中
	{
		path.push_back(a[i][minj]);
		minj = pre[i][minj];
		i--;
	}
	cout << "最短距离路径为：";
	for (vector<int>::reverse_iterator it = path.rbegin(); it != path.rend(); it++)//逆向输出
	{
		cout << *it<<" ";
	}
	cout << endl;
}
int main()
{
	n = 4;
	a[1][1] = 2;
	a[2][1] = 3; a[2][2] = 4;
	a[3][1] = 6; a[3][2] = 5; a[3][3] = 7;
	a[4][1] = 8; a[4][2] = 3; a[4][3] = 9; a[4][4] = 2;
	Search();
	disp();
}