#include<iostream>
using namespace std;
struct Time
{
	int M1;
	int M2;
};
int n = 4;
Time T[4] = { {5,6},{12,2},{4,14},{8,7} };//M1��M2�Բ�ͬ����������ʱ��
int bestx[4];//�����ʱ����̵ķ��䷽��
int x[] = { 1,2,3,4 };//��ŵ�ǰ�ĵ��ȷ���
int bestT=9999999;//���ʱ��
int f1=0;//M1������ʹ�õ�ʱ��
int f2[5] = {0};//M1�ӹ���ɺ�M2���ӹ���ʱ��֮��
void swap(int &a,int &b)//����
{
	int temp = a;
	a = b;
	b = temp;
}
void disp()//���
{
	cout << "���ʱ��Ϊ��" << bestT<<",���ŵ��ȷ���Ϊ��";
	for (int j = 0; j < n; j++)
	{
		cout << bestx[j] << " ";
	}
}
void fun(int i)
{

	if (i == n)
	{
		if (f2[i+1] < bestT)//���ҵ����ŵķ���ʱ����������ʱ����Сʱ
		{
			bestT = f2[i];//������ʱ��
			for (int j = 0; j < n; j++)
			{
				bestx[j] = x[j];//��ŷ��䷽��
			}
		}
	}
	else
	{
		for (int j = i; j < n; j++)
		{
			swap(x[i], x[j]);
			f1 += T[x[i] - 1].M1;//M1�ӹ�����Ҫ��ʱ��
			f2[i + 1] = max(f1, f2[i]) + T[x[i]].M2;//M1�ӹ�����M2�����ӹ���ʱ��
			//��һ�����������M1�ӹ�һ����Ʒ��ʱ�����M2�ӹ���һ����Ʒ��ʱ��ʱ����ʱ��ΪM1�ӹ��������Ʒ��ʱ����������Ʒ��M2��ʱ��
			//�ڶ������������M1�ӹ�һ����Ʒ��ʱ��С��M2�ӹ���һ����Ʒ��ʱ��ʱ����ʱ��ΪM2�ӹ�����һ����Ʒ��ʱ����������Ʒ��M2��ʱ��
			if (f2[i + 1] < bestT)
			{
				fun(i + 1);
			}
			f1 -= T[x[i] - 1].M1;
			swap(x[i], x[j]);
		}
	}

}
int main()
{
	fun(0);
	disp();
}