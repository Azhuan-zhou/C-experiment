#include<iostream>
#define N 20
using namespace std;
int dp[N][N];
int count = 1;
int dfs(int n, int k)
{
	int t;
	if (dp[n][k] != 0)//如果在递归中dp[n][k]已经求解出来，将其储存起来，如果在后续的递归中出现该元素直接返回，无需重新计算
	{
		return dp[n][k];
	}
	if (n == 1 || k == 1)//当拆分的数只有1或者拆分最大数为1时，此时只有一种方案
	{
		dp[n][k] = 1;
		t = dp[n][k];
		cout << "dp[" << n << "]" << "[" << k << "]=" << t<<endl;
		return dp[n][k];
	}
	else if (n < k)
	{
		dp[n][k] = dfs(n,n);
		t = dp[n][k];
		cout << "dp[" << n << "]" << "[" << k << "]=" << "d[" << n << "]" << "[" << n << "]=" << t << endl;
		return dp[n][k];
	}
	else if (n == k)//当正整数n和最大拆分数k相等时，此时的拆分个数等于对n的k-1的最大拆分加上1
	{
		dp[n][k] = dfs(n,k-1)+1;
		t = dp[n][k];
		cout<<"dp[" << n << "]" << "[" << k << "]=" << "d[" << n << "]" << "[" << n - 1 << "]+1=" << t << endl;
		return dp[n][k];
	}
	else
	{
		dp[n][k] = dfs(n - k, k) + dfs(n, k - 1);
		t = dp[n][k];
		cout << "dp[" << n << "]" << "[" << k << "]=" << "d[" << n - k << "]" << "[" << k << "]+" << "d[" << n << "]" << "[" << k - 1 << "]=" << t << endl;
		return dp[n][k];
	}
}
int main()
{
	int n = 5;
	int k = 5;
	int t;
	memset(dp, 0, sizeof(dp));
	t = dfs(n, k);
	cout << "dps(" << n << "," << k << ")=" << t;
}