#include<iostream>
#define N 4
using namespace std;
int W = 6;
struct object
{
    int no;//���
    int w;//����
    int v;//��ֵ
    int p;//��λ�����ļ�ֵ
};
object A[N] = { {1,5,4,0.8},{2,3,4,1.3},{3,2,3,1.5},{4,1,1,1}};//��Ʒ
int x[N];
int maxv = 0, maxw = 0;
void dispsolution()//������
{
	cout << "���䷽����" << endl;
	for (int i = 0; i < N; i++)
	{
		if (x[i] == 1)
		{
			cout << "��" << A[i].no << "����Ʒװ�뱳��������Ϊ" << A[i].w << "kg" << endl;
		}
	}
	cout << "��������" << maxw << ",�ܼ�ֵ��" << maxv << ".";
}
int bound(int i, int tw, int tv)
{
	i++;//��ѡ��ǰ�ڵ����Ʒ
	while (i < N && tw + A[i].w <= W)//�Ͻ纯������ǰ�����������ѡ����Ʒ��������С��
	{
		tw += A[i].w;
		tv += A[i].v;
		i++;
	}
	if (i < N)
	{
		return  tv + (W - tw) * A[i].p;
	}
	else
	{
		return tv;
	}
}
void fun(int i, int tw, int tv, int op[])//rwΪѡ��i�κ�ʣ�µ�i+1��N����Ʒ��������
{
	if (i == N)//������Ʒ���������
	{
		maxv = tv;//��������ֵ
		maxw = tw;//����������
		for (int j = 0; j < N; j++)
		{
			x[j] = op[j];
		}
	}
	else
	{
		//ѡ�񽫵�i����Ʒװ�뱳����
		if (tw + A[i].w <= W)//���ϵ�i����Ʒ������������С����������
		{
			op[i] = 1;
			fun(i + 1, tw + A[i].w, tv + A[i].v, op);
		}
		//��ѡ�񽫵�i����Ʒװ�뱳����
		if (bound(i,tw,tv)>maxv)//����ѡ���i����Ʒ�󣬺�������ѡ�ϵ���Ʒ������������С���������������ܼ�ֵ���ڵ��ȵ�����ֵ
		{
			op[i] = 0;
			fun(i + 1, tw, tv, op);
		}
	}
}
int main()
{
	int op[N];
	fun(0, 0, 0, op);
	dispsolution();
}