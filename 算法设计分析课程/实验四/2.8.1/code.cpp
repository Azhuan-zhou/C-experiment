#include<iostream>
#include<vector>
#define N 20
using namespace std;
int a[N][N] = { {1,3,5,9},{8,1,3,4},{5,0,6,1 },{8,8,4,0} };
//矩阵
int dp[N][N];//dp[i][j]表示从起始点到（i，j）最短的距离
int pre[N][N];//pre[i][j]=1表示前一个结点是向右走到达（i,j），即前一个节点是（i,j-1）
//pre[i][j]=0表示前一个结点是向下走到达（i,j）,即前一个节点是（i-1,j）
int n =4;
void solve()
{
	int i, j;
	//初始化
	dp[0][0] = a[0][0];
	pre[0][0] = -1;//起始点无前驱节点
	for (i = 1; i < n; i++)
	{
		dp[i][0] = dp[i - 1][0] + a[i][0];
		pre[i][0] = 0;//表示向下走
	}
	for (j = 1; j < n; j++)
	{
		dp[0][j] = dp[0][j - 1] + a[0][j];
		pre[0][j] = 1;//表示向右走
	}
	for (i = 1; i < n; i++)
	{
		for (j = 1; j < n; j++)
		{
			if (dp[i - 1][j] < dp[i][j - 1])
			{
				dp[i][j] = dp[i - 1][j] + a[i][j];
				pre[i][j] = 0;//表示向下走
			}
			else
			{
				dp[i][j] = dp[i ][j-1] + a[i][j];
				pre[i][j] = 1;//表示向下走
			}
		}
	}
}
void disp()
{
	vector<int> path;//存放路径
	vector<int>::reverse_iterator it;
	int i = n - 1;
	int j = n - 1;
	path.push_back(a[i][j]);//放入终点
	while (i > 0 && j > 0)
	{
		if (pre[i][j] == 0)//表示前驱节点是向下走的
		{
			path.push_back(a[i - 1][j]);
			i--;
		}
		else
		{
			path.push_back(a[i][j - 1]);
			j--;
		}
	}
	path.push_back(a[0][0]);//放入起始节点
	for (it = path.rbegin(); it != path.rend()-1; it++)
	{
		cout << *it << "→";
	}
	cout <<*it<< endl;
}
int main()
{
	solve();
	cout << "最短路径为：";
	disp();
	cout <<"最短路径和："<< dp[n - 1][n - 1];
}
