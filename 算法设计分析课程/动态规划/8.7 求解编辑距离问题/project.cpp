#include<iostream>
#include<string>
#define N 20
using namespace std;
string b = "gfdgw";
string a = "sfdqxbw";
int dp[N][N];//dp[i][j]��ʾs1ǰi���ַ���s2ǰj���ַ������ٸĶ���
int m, n;
int Count = 1;
void solve()
{
	int i, j;
	for (i = 1; i <= m; i++)
	{
		dp[i][0] = i;
	}
	for (j = 1; j <= n; j++)
	{
		dp[0][j] = j;
	}
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (a[i-1] == b[j-1])
			{
				dp[i][j] = dp[i - 1][j - 1];
				printf("(%d) dp[%d][%d]=dp[%d][%d](%d)+1\n", Count++, i, j, i - 1, j - 1, dp[i - 1][j - 1]);
			}
			else
			{
				dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
				printf("(%d) dp[%d][%d]=min(dp[%d][%d](%d),dp[%d][%d](%d),dp[%d][%d](%d))+1\n", Count++, i, j, i - 1, j - 1, dp[i - 1][j - 1],i,j-1,dp[i][j-1],i-1,j,dp[i-1][j]);
			}
		}
	}
}
int main()
{
	m = a.length();//��
	n = b.length();//��
	solve();
	cout << "  ���ٵ��ַ�����������" << dp[m][n] << endl;
}