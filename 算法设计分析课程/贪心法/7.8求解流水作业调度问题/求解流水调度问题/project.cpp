#include<iostream>
#include<algorithm>
#define N 100
using namespace std;
int n=4;//�ӹ���������
int a[N] = { 5,12,4,8 };//��һ�������ӹ���Ʒ��ʱ��
int b[N] = { 6,2,14,7 };//�ڶ��������ӹ���Ʒ��ʱ��
struct nodetype
{
	int no;//�ӹ����
	int time;//a,b��Сʱ��
	bool group;//���飬1����N1�飬0����N2��
	bool operator<(const nodetype& e)const
	{
		return time < e.time;
	}

};
int best[N];//������ŵ�������
int max(int &a,int& b)//�Ƚϴ�С
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
	int i, j, k;
	//Ϊ��㸳ֵ
	nodetype c[N];
	for (i = 0; i < n; i++)
	{
		c[i].no = i + 1;
		c[i].group = (a[i] < b[i]);
		c[i].time = a[i] < b[i] ? a[i] : b[i];
	}
	sort(c, c + n);
	j = 0;
	k = n - 1;
	for (i = 0; i < n; i++)
	{
		if (c[i].group == 1)
		{
			best[j++] = c[i].no;
		}
		else
		{
			best[k--] = c[i].no;
		}
	}
}
int time()
{
	int f1=0;
	int f2=0;
	for (int i = 0; i < n; i++)
	{
		f1 += a[best[i]-1];
		f2 =max(f2, f1) + b[best[i]-1];
	}
	return f2;
}
int main()
{
	cout << "�����" << endl;
	solve();
	cout << "��ʱ�䣺" << time() << endl;
	cout << "���ȷ�����";
	for (int i = 0; i < n; i++)
	{
		cout << best[i];
	}
	cout << endl;
}