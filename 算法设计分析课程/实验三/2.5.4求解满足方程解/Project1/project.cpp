#include<iostream>
using namespace std;
int a[] = { 1,2,3,4,5 };
int n = 5;
int Count=1;
void swap(int& a, int& b)//����λ��
{
	int temp=a;
	a = b;
	b = temp;
}
void disp()//�����
{
	cout << "��" << Count << "���⣺";
	cout << a[0] << "*" << a[1] << "-" << a[2] << "*" << a[3] << "+" << a[4] << "=1" << endl;
}
void dfs(int i)//�����������i��
{
	if (i==n)//������Ҷ�ӽ��
	{
		if (a[0] * a[1] - a[2] * a[3] - a[4] == 1)
		{
			disp();
			Count++;
		}
	}
	else
	{
		for (int j = i; j < n; j++)//��i�㣬�ӵ�i��Ԫ�ؿ�ʼ�����κͺ����Ԫ�ؽ���λ��
		{
			swap(a[i], a[j]);//����
			dfs(i + 1);//����
			swap(a[i], a[j]);//����
		}
	}
}
int main()
{
	cout << "�������" << endl;
	dfs(0);
}