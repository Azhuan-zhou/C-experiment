#include<iostream>
#define N 4
using namespace std;
int w[] = { 11,13,24,7 };
int W = 31;
int c = 0;
void disp(int x[])//���
{
	cout << "��"<<c<<"����ѡȡ����Ϊ��";
	for (int i = 0; i < N; i++)
	{
		if (x[i] == 1)
		{
			cout << w[i] << " ";
		}
	}
	cout << endl;
}
void fun(int i, int tw, int rw, int op[])
{
	if (i == N)//���������е�Ԫ��
	{
		if (tw == W)//�������ܺ͵���Ҫ����Ӽ���ʱ
		{
			c++;//��ĸ�����һ
			disp(op);
		}
	}
	else
	{
		//��֦��ѡ���i����
		if (tw + w[i] <= W)
		{
			op[i] = 1;
			fun(i + 1, tw + w[i], rw - w[i], op);
		}
		//��֦����ѡ���i����
		if (tw + rw - w[i]>=W)
		{
			op[i] = 0;
			fun(i + 1, tw, rw - w[i], op);
		}
	}
}
int sum(int a[])//���
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += a[i];
	}
	return sum;
}
int main()
{
	int op[N];
	fun(0, 0, sum(w), op);
}