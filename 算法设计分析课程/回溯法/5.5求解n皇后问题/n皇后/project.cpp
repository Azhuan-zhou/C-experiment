#include<iostream>
#define N 100
using namespace std;
int q[N];
int count = 1;
int n;
bool place(int i)//��i���Ƿ���λ�ÿ��Է�
{
	int j=1;
	while (j < i)
	{
		if (q[i] == q[j] || abs(q[i] - q[j]) == i - j)//ͬ�кͶԽ�����
		{
			return false;
		}
		j++;
	}
	return true;
}
void disp()
{
	cout << "��" << ::count++ << "���⣺";
	for (int i = 1; i <= n; i++)
	{
		cout << "(" << i << "," << q[i] << ")"<<" ";
	}
	cout << endl;
}
void solve(int n)
{
	int i = 1;
	q[i] = 0;
	while (i >= 0)//���ݵĽ���
	{
		q[i]++;//��i�У���q[i]�����ڵ�һ��λ����
		while (q[i] <= n && !place(i))
		{
			q[i]++;
		}//����i��q[i]�в��ܷ���ʱ��q[i]++,��̽��һ��
		if (q[i] <= n)//���·�֦
		{
			if (i == n)
			{
				disp();
			}
			else
			{
				i++;
				q[i] = 0;
			}
		}
		else//���q[i]>n,��˵���ڵ�i���Ҳ������ʵ�λ�ã����ݵ���һ��Ϊ��һ�����·�����һ��λ��
		{
			i--;//����
		}
	}
}
int main()
{
	cout << "������n�Ĵ�С��";
	cin >> n;
	cout << "n�ʺ�����������£�" << endl;
	solve(n);
}