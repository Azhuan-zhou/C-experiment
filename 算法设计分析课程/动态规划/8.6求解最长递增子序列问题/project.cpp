#include<iostream>
#define N  9
using namespace std;
int a[] = { 2,1,5,3,6,4,8,9,7 };
int dp[N];
int ans;
int Count = 1;
void solve()
{
	int i,j;
	for (i = 0; i < N; i++)
	{
		dp[i] = 1;
		for (j = 0; j < i; j++)
		{
			if (a[i] > a[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
				cout << "(" << Count++ << ") a[" << i << "](" << a[i] << ") > a[" << j << "](" << a[j] << "):" << "dp[" << i << "]=max(dp[" << i << "](" << dp[i] << "),dp[" << j << "](" << dp[j] << ")+1)=" << dp[i] << endl;
			}
		}
	}
	ans = dp[0];
	for (i = 0; i < N; i++)
	{
		if (dp[i] > ans)
		{
			ans = dp[i];
		}
	}
}
int main()
{
	cout << "求解结果：" << endl;
	solve();
	cout << "         最长连续子序列的个数为：" << ans << endl;
}
