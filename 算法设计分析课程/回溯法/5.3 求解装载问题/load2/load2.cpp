#include<iostream>
#define N 3
using namespace std;
int w[] = { 10,40,40 };//���������
int c1 = 50, c2 = 50;//�ֱ�Ϊ�����ִ������װ����
int x[N];//��ռ�����
int maxw = 0;//��һ���ִ����װ�ػ������
void dispsolution()//������
{
	cout << "���䷽����" << endl;
	for (int i = 0; i < N; i++)
	{
		if (x[i] == 1)
		{
			cout << "��" << i + 1 << "����װ��װ���һ���ִ�������Ϊ" << w[i] << "t" << endl;
		}
		else
		{
			cout << "��" << i + 1 << "����װ��װ��ڶ����ִ�������Ϊ" << w[i] << "t" << endl;
		}
	}
}
void fun(int i, int tw, int rw, int op[])//�ӵ�0��N-1����Ʒѡ��tw�ǵ�ǰ��ѡ����Ʒ����������rw��δѡ����Ʒ��������
{
	if (i == N)//�������м�װ���
	{
		if (tw >= maxw)
		{
			maxw = tw;//����������������ŵ��������򱣴���
			for (int j = 0; j < N; j++)
			{
				x[j] = op[j];//���������
			}
		}

	}
	else
	{
		//��֦
		if (tw + w[i] <= c1)
		{
			op[i] = 1;//ѡ��
			fun(i + 1, tw + w[i], rw - w[i], op);
		}
		//��֦
		if (tw + rw - w[i] >= maxw)
		{
			op[i] = 0;//��ѡ��
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
bool solve()
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (x[i] == 0)
		{
			sum += w[i];
		}
	}
	if (sum <= c2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int op[N];
	fun(0, 0, sum(w), op);
	if (solve())
	{
		cout << "����һ��װ�ط�����" << endl;
		dispsolution();
	}
	else
	{
		cout << "������һ��װ�ط���";
	}
}