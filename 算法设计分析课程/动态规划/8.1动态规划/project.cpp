#include<iostream>
#include<map>
#include<string>
#include<iomanip>
#define N 20
#define INF 0x3f3f3f3f
using namespace std;
int n;//�������
int start;//��ʼ���
int end;//��ֹ���
int c[N][N];//�ڽӾ���
int next[N];//������һ�����
map<int, string> vname;
int dp[N];
int count = 1;
void init()
{
	n = 10;
	start = 0;
	::end = 9;
	memset(c, INF, sizeof(c));
	memset(dp, -1,  sizeof(dp));
	for (int i = 0; i < n; i++)
	{
		c[i][i] = 0;

	}
	//���ٽ�����ʼ��
	c[0][1] = 2;c[0][2] = 4;c[0][3] = 3;
	c[1][4] = 7;c[1][5] = 4;
	c[2][4] = 3;c[2][5] = 2;c[2][6] = 4;
	c[3][4] = 6;c[3][5] = 2;c[3][6] = 5;
	c[4][7] = 3;c[4][8] = 4;
    c[5][7] = 6;c[5][8] = 3;
	c[6][7] = 3;c[6][8] = 3;
	c[7][9] = 3;
	c[8][9] = 4;
	//�����еĽ�����źͱ�ų�ʼ��
	vname[0] = "A";
	vname[1] = "B1"; vname[2] = "B2"; vname[3] = "B3";
	vname[4] = "C1"; vname[5] = "C2"; vname[6] = "C3";
	vname[7] = "D1"; vname[8] = "D2";
	vname[9] = "E";
}
int f(int s)
{
	if (dp[s] != -1)//���ڴ�����s��end������̾���
	{
		return dp[s];
	}
	if (s == n - 1)
	{
		dp[s] = 0;
		cout<<setw(2)<<::count++ <<"  " << "f(" << vname[s] << ")=" << dp[s] << endl;
		return dp[s];
	}
	else
	{
		int cost;
		int mincost = INF;
		int minj{};
		for (int j = 0; j < n; j++)
		{
			if (c[s][j] != 0 && c[s][j] != INF)
			{
				cost = c[s][j] + f(j);//��ǰ���s��j���Ͻ��j����̾���
				if (cost < mincost)
				{
					mincost = cost;
					minj = j;
				}
			}
		}
		dp[s] = mincost;
		::next[s] = minj;//��������s��̾�����j
		cout <<setw(2)<< ::count++ << "  " << "f(" << vname[s] << ")=c(" << vname[s] << "," << vname[minj] << ")+f(" << vname[minj] << ")=" << dp[s] << ",";
		cout << "next(" << vname[s] << ")=" << vname[minj] << endl;
		return dp[s];
	}
}
int main()
{
	init(); cout << INF << endl;
	cout << vname[start] << "��" << vname[::end] << "�������̣�" << endl;
	f(start);
}