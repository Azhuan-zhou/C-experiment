#include<iostream>
#include<queue>
#define INF 0x3f3f3f3f
#define MAX 50
using namespace std;
int cost[MAX][MAX] = { {0},{0,9,2,7,8},{0,6,4,3,7},{0,5,8,1,8},{0,7,6,9,4} };//��i������������j�˵ĳɱ�
int n = 4;//����
int bestx[MAX];//���Ž�����
int bestc = INF;//���ųɱ�
int t = 1;//�����
struct Nodetype
{
	int cost;//���ĳɱ�
	int lb;//�����½�
	int i;//������
	int no;//�����
	bool worker[MAX];//��Ա�Ƿ����������Ĳ�������
	int x[MAX];//������
	bool operator <(const Nodetype& e) const
	{
		return lb > e.lb;
	}
};
void bound(Nodetype& e)
{
	int mincost=e.cost;
	for (int i = e.i+1; i <= n; i++)//�Ӹ�������һ������ʼ����n���������
	{
		int k = INF;
		for (int j = 1; j <= n; j++)//�������е�Ա��
		{
			if (e.worker[j] == false && cost[i][j] < k)//û�з��������Ա�����ҳɱ���͵�
			{
				k = cost[i][j];
			}
		}
		mincost += k;
	}
	e.lb = mincost;
}
void bfs()
{
	priority_queue<Nodetype> que;//���ȶ���
	Nodetype e;//���ڵ�
	Nodetype e1;//�ӽڵ�
	//��ʼ���
	e.i = 0;
	e.cost = 0;
	e.no = t++;
	for (int j = 1; j <= n; j++)
	{
		e.worker[j] = false;
		e.x[j] = 0;
	}
	bound(e);
	//
	que.push(e);//����ʼ�����������ŷ��
	while (!que.empty())
	{
		e = que.top();//������С��lbȷ�����ڵ���չ
		que.pop();//ȥ�������еĸ����
		//�������Ž�
		if (e.i == n)
		{
			if (e.cost < bestc)
			{
				bestc = e.cost;
				for (int j = 1; j <= n; j++)
				{
					bestx[j] = e.x[j];
					cout << e.x[j];
				}
				cout << endl;

			}
		}
		//
		e1.i = e.i + 1;
		for (int j = 1; j <= n; j++)//�������еĹ���
		{
			if (e.worker[j])
			{
				continue;
			}
			for (int i1 = 1; i1 <= n; i1++)//�����ڵ�Ľ�������bool���鸳ֵ���ӽڵ�
			{
				e1.worker[i1] = e.worker[i1];
				e1.x[i1] = e.x[i1];
			}
			e1.worker[j] = true;
			e1.x[e1.i] = j;
			e1.no = t++;
			e1.cost =e.cost + cost[e1.i][j];
			bound(e1);
			//��֦
			if (e1.lb < bestc)
			{
				que.push(e1);
			}
		}
	}
}
int main()
{
	bfs();
	cout << "��������ţ�" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << "��" << i << "�������Ÿ�" << "��" << bestx[i] << "����" << endl;
	}
	cout << "�ܳɱ�Ϊ��" << bestc;
	
}