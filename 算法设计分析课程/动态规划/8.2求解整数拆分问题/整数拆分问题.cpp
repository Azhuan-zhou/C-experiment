#include<iostream>
#define N 20
using namespace std;
int dp[N][N];
int count = 1;
int dfs(int n, int k)
{
	int t;
	if (dp[n][k] != 0)//����ڵݹ���dp[n][k]�Ѿ������������䴢������������ں����ĵݹ��г��ָ�Ԫ��ֱ�ӷ��أ��������¼���
	{
		return dp[n][k];
	}
	if (n == 1 || k == 1)//����ֵ���ֻ��1���߲�������Ϊ1ʱ����ʱֻ��һ�ַ���
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
	else if (n == k)//��������n���������k���ʱ����ʱ�Ĳ�ָ������ڶ�n��k-1������ּ���1
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