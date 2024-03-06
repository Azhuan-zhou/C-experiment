#include<iostream>
#include<string>
#include<vector>
#define N 20
using namespace std;
string a, b;//字符串a和b
int m, n;//字符串a，b的长度
vector<char> subs;
int dp[N][N];//动态数组
void LCSlength()
{
	//初始化
	for (int i = 0; i < m; i++)
	{
		dp[i][0] = 0;
	}
	for (int j = 1; j < n; j++)
	{
		dp[0][j] = 0;
	}
	//开始匹配
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (a[i] == b[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j-1]);//当a[i] 不等于 b[j]时，a序列前i个元素和b前j个元素中相同的元素=max(a序列前i-1个元素和b前j个元素中相同的元素,a序列前i个元素和b前j-1个元素中相同的元素)
			}
		}
	}
}
void buidsubs()
{
	int k = dp[m-1][n-1];
	int i=m-1, j=n-1;
	while (k > 0)
	{
		if (dp[i][j - 1] == dp[i][j])//一行中相邻两元素相等时，列数减1
		{
			j--;
		}
		else if (dp[i][j] == dp[i - 1][j])//一列中相邻元素相等时，行数减1
		{
			i--;
		}
		else//该元素与前面和上面都不相同时，就是a，b序列中相同元素的位置
		{
			subs.push_back(a[i]);
			i--, j--, k--;
		}
	}
}
int main()
{
	a = " abcbdb";
	b = " acbbabdbb";
	m = a.length();
	n = b.length();
	LCSlength();
	buidsubs();
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "最长公共子序列为：";
	vector<char>::reverse_iterator it;
	for (it = subs.rbegin(); it != subs.rend(); it++)
	{
		cout << *it;
	}
	cout << endl;
	cout << "长度：" << dp[m-1][n-1] << endl;;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
 

}