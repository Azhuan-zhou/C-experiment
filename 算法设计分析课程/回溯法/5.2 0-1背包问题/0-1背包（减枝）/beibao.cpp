#include<iostream>
#define N 5
using namespace std;
//ȫ�ֱ���
int w[N] = { 0,5,3,2,1 };//����
int v[N] = { 0,4,4,3,1 };//��ֵ
const int W = 6;//��������
int maxV = 0;//����ֵ
int maxW = 0;
int x[N];
int sum(int a[])
{
	int sum=0;
	for (int i = 0; i < N; i++)
	{
		sum += a[i];
	}
	return sum;
}
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
	cout << "��������" << maxW << ",�ܼ�ֵ��" << maxV << ".";
}
void fun(int i, int tw, int tv, int rw,int op[])//rwΪѡ��i�κ�ʣ�µ�i+1��N����Ʒ��������
{
	if (i == N)//������Ʒ���������
	{
		if (tw <= W && tv >= maxV)//��װ�뱳����Լ������
		{
			maxV = tv;//��������ֵ
			maxW = tw;//����������
			for (int j = 0; j < N; j++)
			{
				x[j] = op[j];
			}
		}
	}
	else
	{
		//ѡ�񽫵�i����Ʒװ�뱳����
		if (tw + w[i] <= W)//���ϵ�i����Ʒ������������С����������
		{
			op[i] = 1;
			fun(i + 1, tw + w[i], tv + v[i],rw-w[i], op);
		}
		//��ѡ�񽫵�i����Ʒװ�뱳����
		if (tw + rw - w[i] >= W)//��ѡ���i����Ʒʱ����ǰ����������ʣ����Ʒ����֮�ʹ�����������
		{
			op[i] = 0;
			fun(i + 1, tw, tv,rw, op);
		}
	}
}
int main()
{
	int op[N];
	int rw = sum(w);
	fun(0, 0, 0,rw, op);
	dispsolution();
}