#include<iostream>
#include<vector>
#define N 20
using namespace std;
int a[N][N] = { {1,3,5,9},{8,1,3,4},{5,0,6,1 },{8,8,4,0} };
//����
int dp[N][N];//dp[i][j]��ʾ����ʼ�㵽��i��j����̵ľ���
int pre[N][N];//pre[i][j]=1��ʾǰһ������������ߵ��i,j������ǰһ���ڵ��ǣ�i,j-1��
//pre[i][j]=0��ʾǰһ������������ߵ��i,j��,��ǰһ���ڵ��ǣ�i-1,j��
int n =4;
void solve()
{
	int i, j;
	//��ʼ��
	dp[0][0] = a[0][0];
	pre[0][0] = -1;//��ʼ����ǰ���ڵ�
	for (i = 1; i < n; i++)
	{
		dp[i][0] = dp[i - 1][0] + a[i][0];
		pre[i][0] = 0;//��ʾ������
	}
	for (j = 1; j < n; j++)
	{
		dp[0][j] = dp[0][j - 1] + a[0][j];
		pre[0][j] = 1;//��ʾ������
	}
	for (i = 1; i < n; i++)
	{
		for (j = 1; j < n; j++)
		{
			if (dp[i - 1][j] < dp[i][j - 1])
			{
				dp[i][j] = dp[i - 1][j] + a[i][j];
				pre[i][j] = 0;//��ʾ������
			}
			else
			{
				dp[i][j] = dp[i ][j-1] + a[i][j];
				pre[i][j] = 1;//��ʾ������
			}
		}
	}
}
void disp()
{
	vector<int> path;//���·��
	vector<int>::reverse_iterator it;
	int i = n - 1;
	int j = n - 1;
	path.push_back(a[i][j]);//�����յ�
	while (i > 0 && j > 0)
	{
		if (pre[i][j] == 0)//��ʾǰ���ڵ��������ߵ�
		{
			path.push_back(a[i - 1][j]);
			i--;
		}
		else
		{
			path.push_back(a[i][j - 1]);
			j--;
		}
	}
	path.push_back(a[0][0]);//������ʼ�ڵ�
	for (it = path.rbegin(); it != path.rend()-1; it++)
	{
		cout << *it << "��";
	}
	cout <<*it<< endl;
}
int main()
{
	solve();
	cout << "���·��Ϊ��";
	disp();
	cout <<"���·���ͣ�"<< dp[n - 1][n - 1];
}
