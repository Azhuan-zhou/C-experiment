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
void dispsolution()//������
{
	cout << "���䷽����"<<endl;
	for (int i = 0; i < N; i++)
	{
		if (x[i] == 1)
		{
			cout << "��" << i + 1 << "����Ʒװ�뱳��������Ϊ" << w[i] << "kg" << endl;
		}
	}
	cout << "��������" << maxW << ",�ܼ�ֵ��" << maxV << ".";
}
void fun(int i, int tw, int tv, int op[])
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
		op[i] = 1;
		fun(i + 1, tw + w[i], tv + v[i], op);
		//��ѡ�񽫵�i����Ʒװ�뱳����
		op[i] = 0;
		fun(i + 1, tw, tv, op);
	}
}
int main()
{
	int op[N];
	fun(0, 0, 0, op);
	dispsolution();
}