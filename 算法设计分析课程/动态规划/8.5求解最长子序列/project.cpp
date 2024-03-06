#include<iostream>
#include<string>
#include<vector>
#define N 20
using namespace std;
string a, b;//�ַ���a��b
int m, n;//�ַ���a��b�ĳ���
vector<char> subs;
int dp[N][N];//��̬����
void LCSlength()
{
	//��ʼ��
	for (int i = 0; i < m; i++)
	{
		dp[i][0] = 0;
	}
	for (int j = 1; j < n; j++)
	{
		dp[0][j] = 0;
	}
	//��ʼƥ��
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
				dp[i][j] = max(dp[i - 1][j], dp[i][j-1]);//��a[i] ������ b[j]ʱ��a����ǰi��Ԫ�غ�bǰj��Ԫ������ͬ��Ԫ��=max(a����ǰi-1��Ԫ�غ�bǰj��Ԫ������ͬ��Ԫ��,a����ǰi��Ԫ�غ�bǰj-1��Ԫ������ͬ��Ԫ��)
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
		if (dp[i][j - 1] == dp[i][j])//һ����������Ԫ�����ʱ��������1
		{
			j--;
		}
		else if (dp[i][j] == dp[i - 1][j])//һ��������Ԫ�����ʱ��������1
		{
			i--;
		}
		else//��Ԫ����ǰ������涼����ͬʱ������a��b��������ͬԪ�ص�λ��
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
	cout << "�����������Ϊ��";
	vector<char>::reverse_iterator it;
	for (it = subs.rbegin(); it != subs.rend(); it++)
	{
		cout << *it;
	}
	cout << endl;
	cout << "���ȣ�" << dp[m-1][n-1] << endl;;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
 

}