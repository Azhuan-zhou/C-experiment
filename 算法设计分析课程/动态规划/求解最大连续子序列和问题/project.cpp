#include<iostream>
#define N 20
using namespace std;
int dp[N];//dp[i]��ʾ��i��λ��ǰ���������������
int n;
int a[] = { 0,-2,11,-4,13,-5,-2 };
int max(int a, int b)//�ҵ����ֵ
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
void maxsubsum()
{
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = max(dp[i-1] + a[i], a[i]);//״̬ת��
	}
}
void dispmaxsum()
{
	int maxj=1;
	for (int i = 2; i < n; i++)
	{
		if (dp[i] > dp[maxj])
		{
			maxj = i;
		}
	}
	cout << "������������к�Ϊ��"<<dp[maxj]<<endl;
	cout << "�������������Ϊ��" ;
	for (int j = maxj; j >= 1; j--)
	{
		if (dp[j] < 0)
		{
			break;
		}
		cout << a[j] << " ";
	}
	cout << endl;
}
int main()
{
	n = 6;
	maxsubsum();
	cout << "�����Ϊ��" << endl;
	dispmaxsum();
}