#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int n = 5;//�������
int w[] = { 0,5,2,6,4,3 };//��������
int W = 10;//�ִ���������
int maxw;
int x[5];
void solve()
{
	sort(w + 1, w + n + 1);
	maxw = 0;
	for (int i = 1; i <= n; i++)
	{
		maxw += w[i];
		x[i] = 1;
		if (maxw > W)
		{
			maxw = maxw - w[i];
			x[i] = 0;
			break;
		}

	}
}
void disp()
{
	for (int i = 0; i <= n; i++)
	{
		if (x[i] == 1)
		{
			cout <<setw(2)<< "ѡȡ����Ϊ" << w[i] << "�ļ�����" << endl;
		}
	}
	cout << "������:" << maxw;
}
int main()
{
	solve();
	disp();
}