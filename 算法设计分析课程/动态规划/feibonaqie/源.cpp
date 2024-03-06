#include<iostream>
#define N 20
using namespace std;
int dp[N];
int main()
{
	dp[0] = 1;
	cout << "dp[" << 0 << "]=" << dp[0]<<endl;
	dp[1] = 1;
	cout << "dp[" << 1 << "]=" << dp[1] << endl;
	for (int i = 2; i < N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		printf("dp[%d]=%d+%d=%d\n", i, dp[i - 1], dp[i - 2],dp[i]);
	}
	printf("dp[19]/dp[20]=%lf", (double)dp[18] / dp[19]);
}