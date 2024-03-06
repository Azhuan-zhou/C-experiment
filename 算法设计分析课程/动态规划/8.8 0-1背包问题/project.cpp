#include<iostream>
#include<iomanip>
#define N 20
using namespace std;
int dp[N][N];
int w[] = {0, 2, 2, 6, 5, 4};//质量
int v[] = {0,6,3,5,4,6};//价值
int x[N];//存放解向量
int n = 5;//物品数量
int W = 10;//背包上限质量
int maxv = 0;
int max(int &a, int &b)//求解最大值
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
	int i, r;
	for (i = 0; i <= n; i++)
	{
		dp[i][0] = 0;
	}
	for (r = 0; r <= W; r++)
	{
		dp[0][r] = 0;
	}
	for (i = 1; i <= n; i++)
	{
		for (r = 1; r <= W; r++)
		{
			if (r < w[i])//剩余质量小于第i个物品的质量
			{
				dp[i][r] = dp[i - 1][r];
			}
			else//剩余质量大于第i个物品的质量
			{
				dp[i][r] = max(dp[i - 1][r], dp[i - 1][r - w[i]] + v[i]);//在不选择第i个物品和选择d
			}
		}
	}
}
void build()
{
	int i = n;
	int r = W;
	while (i >= 0)
	{
		if (dp[i - 1][r] != dp[i][r])//当第i个物品放入时
		{
			x[i] = 1;
			r = r - w[i];
			maxv += v[i];
		}
		else
		{
			x[i] = 0;
		}
		i--;
	}
}
int main()
{
	cout << "求解结果(最优方案)" << endl;
	solve();
	build();
	cout << "选择物品：";
	for (int i = 1; i <= n; i++)
	{
		if (x[i] == 1)
		{
			cout << i << " ";
		}
	}
	cout << endl;
	cout << "总价值：" << maxv << endl;
}