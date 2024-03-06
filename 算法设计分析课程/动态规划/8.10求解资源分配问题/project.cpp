#include<iostream>
#define N 20
using namespace std;
int v[N][N] = { {0,3,7,9,12,13},{0,5,10,11,11,11},{0,4,6,11,12,12} };//v[i][j]表示店铺i拥有人数j时的利润额度
int dp[N][N];//dp[i][j]表示总人数上限为j时第i个店铺的最大利润
int num[N][N];
int m = 5;
int n = 3;
void solve()
{
	int i, j, k;//循环第i行j列，在[0,j]找到店铺
	for (i = 1; i <= n; i++)//对店铺[1,n]循环
	{
		for (j = 1; j <= m; j++)//人数上限为j
		{
			int maxf = 0;
			int maxj = 0;
			for (k = 0; k <= j; k++)//对于第i个店铺选择了k个人
			{
				if (maxf <= dp[i - 1][j - k] + v[i][k])
				{
					maxf = dp[i - 1][j - k] + v[i][k];
					maxj = k;
				}
			}
			dp[i][j] = maxf;
			num[i][j] = maxj;
		}
	}
}
void disp()
{
	int k, r, s;
	s = num[n][m];//这一阶段
	r = m - s;//下一阶段
	for(k=n;k>=1;k--)
	{
		cout << (char)('A' + k - 1) << "店铺安排" << s << "个人" << endl;
		s = num[k - 1][r];
		r = r - s;
	}
	cout << "店铺总利润额为：" << dp[n][m];
}
int main()
{
	memset(dp, 0, sizeof(dp));
	memset(num, 0, sizeof(num));
	solve();
	disp();
}