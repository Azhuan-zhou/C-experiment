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
	int i, j;//ѭ���к���
	int k;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= W; j++)
		{
			for (k = 0; k * w[i] <= j; k++)//�ҳ���ѡ���i����Ʒ���ͣ�1....k������i����Ʒ�������Ǹ�
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
	//��dp��������һ��Ԫ�ؿ�ʼѡȡ
	int i = n;
	int j = W;
	while (i>=1)
	{
		cout << "         ��" << i << "����Ʒ����" << fp[i][j] << "��" << endl;
		j = j - fp[i][j] * w[i];
		i--;
	}
}
int main()
{
	memset(dp, 0, sizeof(dp));
	memset(fp, 0, sizeof(fp));
	cout << "���Ž⣺" << endl;
	solve();
	cout << "�ܼ�ֵ=" << dp[n][W]<<endl;
	cout << "ѡ�񷽰���" << endl;
	disp();
}