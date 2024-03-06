#include<iostream>
#include<queue>
#define N 2001
using namespace std;
int n = 3;//��Ʒ����
int w[] = {0,16,15,15};//��Ʒ����
int v[] = { 0,45,25,25 };//��Ʒ��ֵ
int bestw = 0;//������Ʒ���������
int bestv = 0;//������Ʒ�����ż�ֵ
int W = 30;//������������
int bestx[N];//�����ѷ���
int Number = 0;
struct Nodetype
{
	int i;//��ǰ����������ռ�Ĳ��
	int No;//�����ţ���1��ʼ��
	int w;//��������
	int v;//���ļ�ֵ
	int x[N];//���Ľ�ռ�
	int ub;//�����Ͻ�
};
void bound(Nodetype& e)
{
	int i = e.i+1;
	int sumw = e.w;
	int sumv = e.v;
	while (sumw + w[i] <= W && i <= n)//����С�ڱ������޲����������С�ڵ���3
	{
		sumw += w[i];//�������ǰ������ʣ������������������Ʒ����
		sumv += v[i];//�������ǰ������ʣ������������������Ʒ��ֵ
		i++;
	}
	if (i <= n)
	{
		 e.ub = sumv + (W - sumw) * (v[i] / w[i]);//�����i+1����Ʒ�Ų��£����������W��ʣ�࣬����ʣ���������Ը���Ʒ��λ�������룬�Ͻ�sumv + (W - sumw) * (v[i] / w[i]
		 //��Ϊ����ʱ�ĸ���i+1���������Ʒ���룬����󱳰�����������ܻ�С�����ֵ
	}
	else
	{
		e.ub = sumv;//�����е�������ζ���������Ͻ�͵���sumv
	}
}
void Enqueue(Nodetype e,queue<Nodetype> &qu)
{
	if (e.i == n)//��������δﵽҶ�ӽ��ʱ����㲻�������
	{
		if (e.v > bestv)
		{
			bestv = e.v;
			for (int j = 1; j <= n; j++)
			{
				bestx[j] = e.x[j];
			}
		}
	}
	else
	{
		qu.push(e);//��û�дﵽҶ�ӽڵ�ʱ�����������
	}
}
void fun()
{
	Nodetype e;//���ڵ�
	Nodetype e1;//����չ���
	Nodetype e2;//����չ���
	queue<Nodetype> qu;
	//������ʼ���
	e.i = 0;//��ʼ�ڵ��������
	e.No = Number++;//��ʼ������
	e.w = 0;//��ʼ�������
	e.v = 0;//��ʼ����ֵ
	for (int j = 0; j <= n; j++)
	{
		e.x[j] = 0;//��ʼ���Ľ�ռ�
	}
	bound(e);//��ʼ�����Ͻ�
	qu.push(e);//����ʼ���������
	while (!qu.empty())//�����в�Ϊ��ʱ
	{
		e = qu.front();//���ڵ�
		qu.pop();//�������Ӷ�����ɾȥ
		//��֦��e1Ϊ��չ��㣩
		if (e.w + w[e.i + 1] <= W && e.i <= n)//���������֦
		{
			e1.v = e.v + w[e.i + 1];//������һ����Ʒ�ļ�ֵ
			e1.w = e.w + w[e.i + 1];//������һ����Ʒ������
			e1.i = e.i + 1;//������μ�һ
			e1.No = Number++;//�����ż�һ
			for (int j = 0; j <= e.i; j++)
			{
				e1.x[j] = e.x[j];//���Ƹ��ڵ�Ľ�ռ�
			}
			e1.x[e1.i] = 1;//����ѡ������һ����Ʒ����λ�õĽ�ռ��Ϊ1
			bound(e1);
			Enqueue(e1, qu);//������չ���������
		}
		//��֦��e2Ϊ��չ��㣩
		e2.v = e.v ;//��������һ����Ʒ�ļ�ֵ
		e2.w = e.w ;//��������һ����Ʒ������
		e2.i = e.i + 1;//������μ�һ
		e2.No = Number++;//�����ż�һ
		for (int j = 0; j <= e.i; j++)
		{
			e2.x[j] = e.x[j];//���Ƹ��ڵ�Ľ�ռ�
		}
		e2.x[e2.i] = 0;//����û��ѡ����һ����Ʒ����λ�õĽ�ռ��Ϊ0
		bound(e2);
		if (e2.ub > bestv)//���Ͻ���ڵ�ǰ����ֵʱ�ſ��ܴ��ڱ�����ֵ��ķ���
		{
			Enqueue(e2, qu);
		}
		
	}
	
}
int main()
{
	fun();
	cout << "��֧���޷����0-1�������⣺" << endl;
	cout << "X=[ ";
	for (int i = 1; i <= n; i++)
	{
		cout << bestx[i] << " ";
	}
	cout << "],�ܼ�ֵΪ��"<<bestv;
}