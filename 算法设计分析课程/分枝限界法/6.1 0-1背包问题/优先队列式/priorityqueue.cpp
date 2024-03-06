#include<iostream>
#include<queue>
#define N 10
using namespace std;
int n = 3;//��Ʒ����
int w[] = { 0,16,15,15 };//��Ʒ����
int W = 30;//��������������
int v[] = { 0,45,25,25 };//��Ʒ��ֵ
int bestw=0;//���ŷ���������
int bestv=0;//���ŷ����ļ�ֵ
int bestx[N];//���ŷ����Ľ�����
int number = 0;
struct Nodetype
{
	int i;//�������
	int no;//�����ţ���1��ʼ
	int w;//��㱳���е�����
	int v;//��㱳���еļ�ֵ
	int x[N];//���Ľ�����
	double ub;//�����Ͻ�
	bool operator<(const Nodetype& e) const
	{
		return ub < e.ub;//���ع�ϵ�������<��,ʹ�����ȶ���
	}
};
void bound(Nodetype &e)//�Ͻ纯��
{
	int i = e.i + 1;
	int sumw = e.w;
	int sumv = e.v;
	while (sumw + w[i] <= W && i <= n)
	{
		sumw += w[i];
		sumv += v[i];
		i++;
	}
	if (i <= n)
	{
		e.ub = sumv + (W - sumw) * ((double)v[i] / w[i]);
	}
	else
	{
		e.ub = (double)sumv;
	}
}
void Enqueue(Nodetype e, priority_queue<Nodetype>& qu)//����������еĺ���
{
	if (e.i == n)//�ﵽҶ�ӽ��ʱ���������
	{
		if (e.v > bestv)
		{
			bestv = e.v;
		}
		for (int j = 1; j <= n; j++)
		{
			bestx[j] = e.x[j];
		}
	}
	else//û�дﵽҶ�ӽ�����
	{
		qu.push(e);
	}
}
void fun()
{
	Nodetype e;//���ڵ�
	Nodetype e1;//���ӽ��
	Nodetype e2;//�Һ��ӽ��
	priority_queue<Nodetype> qu;
	//�Ը��ڵ��ʼ��
	e.i = 0;
	e.w = 0;
	e.v = 0;
	e.no = number++;
	bound(e);
	for (int j = 1; j <= n; j++)
	{
		e.x[j] = 0;
	}
	qu.push(e);
	while (!qu.empty())
	{
		//��֦��ѡ����һ��������Ʒ
		e = qu.top();
		qu.pop();
		if (e.w + w[e.i + 1] <= W)
		{
			e1.i = e.i + 1;
			e1.w = e.w + w[e1.i];
			e1.v = e.v + v[e1.i];
			e1.no = number++;
			for (int j = 1; j <= e.i; j++)
			{
				e1.x[j] = e.x[j];
			}
			e1.x[e1.i] = 1;
			bound(e1);
			Enqueue(e1, qu);
		}
		//��֦����ѡ����һ��������Ʒ
		e2.i = e.i + 1;
		e2.w = e.w;
		e2.v = e.v;
		e2.no = number++;
		for (int j = 1; j <= e.i; j++)
		{
			e2.x[j] = e.x[j];
		}
		e2.x[e2.i] = 0;
		bound(e2);
		if (e2.ub > bestv)
		{
			Enqueue(e2, qu);
		}
	}
}
int main()
{
	fun();
	cout << "��֧���޵����ȶ��н��0-1�������⣺" << endl;
	cout << "X=[ ";
	for (int j = 1; j <= n; j++)
	{
		cout << bestx[j] << " ";
	}
	cout << "],��Ʒ�ļ�ֵΪ��"<<bestv;

}