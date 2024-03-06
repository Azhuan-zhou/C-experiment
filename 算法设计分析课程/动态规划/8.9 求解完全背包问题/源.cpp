#include<iostream>
#define N 20
using namespace std;
int dp[N][N];
int fp[N][N];
int W = 7;
int n = 3;
int w[] = {0,3,4,2 };
int v[] = {0,4,5,3};

void solve()
{
	int i, j;//循环行和列
	int k;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= W; j++)
		{
			for (k = 0; k * w[i] <= j; k++)//找出不选择第i个物品，和（1....k）个第i个物品中最大的那个
			{
				if (dp[i][j] < dp[i - 1][j - k * w[i]] + k * v[i])
				{
					dp[i][j] = dp[i - 1][j - k * w[i]] + k * v[i];
					fp[i][j] = k;
				}
			}
		}
	}
}
void disp()
{
	//从dp数组的最后一个元素开始选取
	int i = n;
	int j = W;
	while (i>=1)
	{
		cout << "         第" << i << "个物品放入" << fp[i][j] << "个" << endl;
		j = j - fp[i][j] * w[i];
		i--;
	}
}
int main()
{
	memset(dp, 0, sizeof(dp));
	memset(fp, 0, sizeof(fp));
	cout << "最优解：" << endl;
	solve();
	cout << "总价值=" << dp[n][W]<<endl;
	cout << "选择方案：" << endl;
	disp();
}