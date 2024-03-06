#include<iostream>
#include<iomanip>
#include<algorithm>
#define MAX 20
using namespace std;
int a[MAX];//��ɵ���
int b[MAX];//����������
int n;//�������
int money;
void solve()
{
	money = 0;
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	int lefta = 1, leftb = 1;//����
	int righta = n, rightb = n;//����
	while (lefta <= righta)
	{
		if (a[righta] > b[rightb])//��ɵĿ����ٶȴ����������Ŀ����ٶ�
		{
			righta--;//���������������������������
			rightb--;
			money += 200;
		}
		else if (a[righta] < b[rightb])//��ɵĿ����ٶ�С�����������Ŀ����ٶ�
		{
			lefta++;//�����������������������������
			rightb--;
			money -= 200;
		}
		else
		{
			if (a[lefta] > b[leftb])//��ɵ������ٶȴ������������������ٶ�
			{
				lefta++;//�������������������������������
				leftb++;
				money += 200;
			}
			else if(a[lefta]<b[leftb])//��ɵ������ٶ�С�����������������ٶ�
			{
				lefta++;
				leftb++;
				money -= 200;
			}
			else
			{
				lefta++;
				leftb++;
			}
		}
	}
}
void disp()
{
	cout << "���Ӯ�õ�Ǯ��" << money;
}
int main()
{
	while (true)
	{
		cin >> n;
		if (n == 0)
		{
			break;
		}
		for (int i = 1; i <= n; i++)//�����������ٶ�
		{
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++)//��������������ٶ�
		{
			cin >> b[i];
		}
		solve();
		disp();
	}
	
}