#include<iostream>
#include<queue>
#define MAX 20
#define INF 0x3f3f3f3f
using namespace std;
int t = 1;//�����
int n = 4;//�ӹ�����Ʒ����
int M1[] = { 0,5,12,4,8 };//��Ʒ��M1�ӹ���ʱ��
int M2[] = { 0,6,2,14,7};//��Ʒ��M2�ӹ���ʱ��
int mint = INF;//�ӹ����ʱ��
int bestx[MAX];//���Ž�����
struct Nodetype
{
	int no;//�����
	int f1;//��Ʒ��M1�ӹ�����ʱ��
	int f2;//��Ʒ��M2�ӹ�����ʱ��
	bool object[MAX];//object[i]=true ��ʾ��i����Ʒ�Ѿ����ӹ�
	int x[MAX];// x[i]=j ��ʾ��i���ӹ�j��Ʒ
	int i;//������
	int lb;//��С�½�
	bool operator <(const Nodetype& e)const//���������
	{
		return lb > e.lb;
	}
};
void bound(Nodetype& e)
{
	int sumt = e.f2;
	for (int i = 1; i <= n;i++)
	{
		if (e.object[i] == false)
		{
			sumt += M2[i];
		}
		
	}
	e.lb = sumt;
}
int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
void bfs()
{
	priority_queue<Nodetype> que;//���ȶ���
	Nodetype e;//���ڵ�
	Nodetype e1;//�ӽڵ�
	//��ʼ����ʼ��
	memset(e.x, 0, sizeof(e.x));
	memset(e.object, false, sizeof(e.object));
	e.i = 0;
	e.no = t++;
	e.f1 = 0;
	e.f2 = 0;
	bound(e);
	que.push(e);
	while (!que.empty())
	{
		e = que.top();//������ڵ�
		que.pop();//ɾȥ���ڵ�
		//��չ���
		e1.i = e.i + 1;
		for (int j = 1; j <= n; j++)//�������е���Ʒ
		{
			if (e.object[j] == true)//�����Ʒj�Ѿ�������ˣ��������һ��ѭ��
			{
				continue;
			 }

			for (int i1 = 1; i1 <= n; i1++)
			{
				e1.x[i1] = e.x[i1];
				e1.object[i1] = e.object[i1];
			}
			e1.x[e1.i] = j;
			e1.object[j] = true;
			e1.f1 = e.f1 + M1[j];
			e1.f2 = max(e1.f1, e.f2) + M2[j];
			e1.no = t++;
			bound(e1);

			//���ﵽҶ�ӽ��ʱ���жϴ������Ž�
			if (e1.i == n)
			{
				if (e1.f2 < mint)
				{
					mint = e1.f2;
					for (int j = 1; j <= n; j++)
					{
						bestx[j] = e1.x[j];
					}

				}
			}
			//
			if (e1.lb < mint)//����С�½�С��Ŀǰ������ֵʱ��˵�����Ÿ�·�����ҵ�һ����Ŀǰ���ŵ�ֵ
			{
				que.push(e1);
			}
		}
	}
}
int main()
{
	bfs();
	cout << "���żӹ�����Ϊ��" << endl;
	for (int j = 1; j <= n; j++)
	{
		cout << "��" << j << "���ӹ�" << bestx[j] << endl;
	}
	cout << "��С�ӹ�ʱ��Ϊ��" << mint;
}