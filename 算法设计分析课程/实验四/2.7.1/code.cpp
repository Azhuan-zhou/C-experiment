#include<iostream>
#include<algorithm>
#define N 20
using namespace std;
int a[N];
int n;
int maxn;
int bestd;
void solve()
{
	sort(a, a + n);
	maxn = 1;
	bestd = a[0];
	int pred;//���浱ǰ������������е�ֵ
	int num=0;//���浱ǰ������������е�ֵ
	int i=0;//�ӵ�һ��Ԫ�ؿ�ʼ
	while (i < n)
	{
		pred = a[i];
		//���㵱ǰ����Ԫ�صĸ���
		while (i<n && pred == a[i])//a[i-1]��a[i]������ʱ�˳�
		{
			i++;
			num++;
		}
		if (num > maxn)
		{
			maxn = num;
			bestd = pred;
		}
		num = 0;//����
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "�����̣�" << endl;
	solve();
	cout << "���ִ�������Ԫ��Ϊ��" << bestd << ",�����Ϊ��" << maxn << endl;
}
