#include<iostream>
#define N 100
using namespace std;
int dp[N];//×´Ì¬º¯Êý
int main()
{
	int n = N;
	dp[0] = 1;
	dp[1] = 1;
	cout << dp[0] << " " << dp[1] << ' ';
	for (int i = 2; i <= 10; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		cout << dp[i] << ' ';
	}
	return 0;
}