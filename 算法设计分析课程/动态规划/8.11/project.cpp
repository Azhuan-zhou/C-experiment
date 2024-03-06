#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define N 20
using namespace std;
struct Activity
{
	int b;//��ʼʱ��
	int e;//����ʱ��
	int length;//���ʱ�䳤��
	bool operator <(const Activity& A)const
	{
		return e < A.e;//����ս���ʱ���������
	}
};
int n = 11;
Activity A[N] = { {1,4},{3,5},{0,6},{5,7},{3,8},{5,9},{6,10},{8,11},{8,12},{2,13},{12,15} };
int dp[N];
int pre[N];
void solve()
{
	memset(dp, 0, sizeof(dp));
	sort(A, A + n);
	dp[0] = 0;
	pre[0] = -1;
	for (int i = 1; i < n; i++)
	{
		int low = 0;
		int high = i - 1;
		while (low <= high)//���ֲ��ң����Ҿٰ������ʱ����ӽ��i�ٰ��ʱ��
		{
			int mid = (high + low) / 2;
			if (A[mid].e <= A[i].b)//�i�ٰ�ǰ���Ծٰ�mid������mid������м�������
			{
				low = mid + 1;
			}
			else // �i�ٰ�ǰ�����Ծٰ�mid������midǰ�����м�������
			{
				high = mid-1;
			}
		}
		if (low == 0)
		{
			if (dp[i - 1] >= A[i].length)//��ѡ���i���
			{
				dp[i] = dp[i - 1];
				pre[i] = -2;
			}
			else
			{
				dp[i] = A[i].length;
				pre[i] = -1;//û��ǰ������
			}
		}
		else
		{
			if (dp[i - 1] >= dp[low - 1] + A[i].length)//��ѡ�񶩵�
			{
				dp[i] = dp[i - 1];
				pre[i] = -2;
			}
			else
			{
				dp[i] = dp[low-1]+A[i].length;
				pre[i] = low-1;//û��ǰ������
			}
		}
	}
}
void disp()
{
	vector<int> res;
	int i = n - 1;
	while (true)
	{
		if (i == -1)
		{
			break;
		}
		if (pre[i] == -2)
		{
			i--;
		}
		else
		{
			res.push_back(i);
			i = pre[i];
		}
	}
	vector<int>::reverse_iterator it;
	cout << "ѡ��Ķ���Ϊ��" << endl;
	for (it = res.rbegin(); it != res.rend(); it++)
	{
		printf("%d[%d,%d]", *it, A[*it].b, A[*it].e);
	}
	cout << endl;
	cout << "���ݶ�������ʱ��Ϊ��" << dp[n - 1] << endl;
}
int main()
{
	int i;
	for(i=0;i<n;i++)
	{ 
		A[i].length = A[i].e - A[i].b;
	}
	solve();
	disp();
}