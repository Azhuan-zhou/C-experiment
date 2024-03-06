#include<iostream>
#define N 20
using namespace std;
int v[N][N] = { {0,3,7,9,12,13},{0,5,10,11,11,11},{0,4,6,11,12,12} };//v[i][j]��ʾ����iӵ������jʱ��������
int dp[N][N];//dp[i][j]��ʾ����������Ϊjʱ��i�����̵��������
int num[N][N];
int m = 5;
int n = 3;
void solve()
{
	int i, j, k;//ѭ����i��j�У���[0,j]�ҵ�����
	for (i = 1; i <= n; i++)//�Ե���[1,n]ѭ��
	{
		for (j = 1; j <= m; j++)//��������Ϊj
		{
			int maxf = 0;
			int maxj = 0;
			for (k = 0; k <= j; k++)//���ڵ�i������ѡ����k����
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
	s = num[n][m];//��һ�׶�
	r = m - s;//��һ�׶�
	for(k=n;k>=1;k--)
	{
		cout << (char)('A' + k - 1) << "���̰���" << s << "����" << endl;
		s = num[k - 1][r];
		r = r - s;
	}
	cout << "�����������Ϊ��" << dp[n][m];
}
int main()
{
	memset(dp, 0, sizeof(dp));
	memset(num, 0, sizeof(num));
	solve();
	disp();
}