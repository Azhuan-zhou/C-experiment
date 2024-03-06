#include<iostream>
#include<iomanip>
#define N 20
using namespace std;
int dp[N][N];
int w[] = {0, 2, 2, 6, 5, 4};//����
int v[] = {0,6,3,5,4,6};//��ֵ
int x[N];//��Ž�����
int n = 5;//��Ʒ����
int W = 10;//������������
int maxv = 0;
int max(int &a, int &b)//������ֵ
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
			if (r < w[i])//ʣ������С�ڵ�i����Ʒ������
			{
				dp[i][r] = dp[i - 1][r];
			}
			else//ʣ���������ڵ�i����Ʒ������
			{
				dp[i][r] = max(dp[i - 1][r], dp[i - 1][r - w[i]] + v[i]);//�ڲ�ѡ���i����Ʒ��ѡ��d
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
		if (dp[i - 1][r] != dp[i][r])//����i����Ʒ����ʱ
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
	cout << "�����(���ŷ���)" << endl;
	solve();
	build();
	cout << "ѡ����Ʒ��";
	for (int i = 1; i <= n; i++)
	{
		if (x[i] == 1)
		{
			cout << i << " ";
		}
	}
	cout << endl;
	cout << "�ܼ�ֵ��" << maxv << endl;
}