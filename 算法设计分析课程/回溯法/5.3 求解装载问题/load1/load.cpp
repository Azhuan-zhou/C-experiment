#include<iostream>
#define N 5
using namespace std;
int w[] = { 5,2,6,4,3 };
int W = 10;
int x[N];
int maxw = 0, maxv = 0;
void dispsolution()//������
{
	cout << "���䷽����" << endl;
	for (int i = 0; i < N; i++)
	{
		if (x[i] == 1)
		{
			cout << "��" << i + 1 << "����Ʒװ�뱳��������Ϊ" << w[i] << "kg" << endl;
		}
	}
	cout << "��������" << maxw <<  ".";
}
void fun(int i, int tw, int rw, int op[])//�ӵ�0��N-1����Ʒѡ��tw�ǵ�ǰ��ѡ����Ʒ����������rw��δѡ����Ʒ��������
{
	if (i == N)
	{
		if (tw <= W)
		{
			maxw = tw;
			for (int j = 0; j < N; j++)
			{
				x[j] = op[j];
			}
		}
		
	}
	else
	{
		//��֦
		if (tw + w[i] <= W)
		{
			op[i] = 1;
			fun(i + 1, tw + w[i], rw - w[i], op);
		}
		//��֦
		if (tw + rw - w[i] >= W)
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
	dispsolution();
}