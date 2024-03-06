#include<iostream>
#include<vector>
#include<queue>
#define INF 0x3f3f3f3f
#define MAX 50
using namespace std;
int n;//������
int dist[MAX];//�������ľ���
int prev[MAX];//������һ�����
int v = 0;//��ʼ�����
int a[MAX][MAX];//�ڽӾ���
struct Nodetype
{
	int vno;//�����
	int length;//��ʼ�ڵ㵽�ý��� ·������
	bool operator<(const Nodetype& e)const
	{
		return length > e.length;//������С�����ȳ�ȥ
	}
};
void addedge(int i, int j, int w)
{
	a[i][j] = w;//���i�����j�ľ���Ϊw
}
void dfs(int v)
{
	Nodetype e;//�����
	Nodetype e1;//���ӽ��
	priority_queue<Nodetype> que;//��Ŷ��ӽ��Ķ���
	e.vno = 0;
	e.length = 0;
	dist[v] = 0;
	que.push(e);
	while (!que.empty())
	{
		e = que.top();//�����еĵ�һ��Ԫ����Ϊ���ڵ���չ
		que.pop();//ɾȥ���ڵ�
		for (int j = 0; j < n; j++)//�����н�����һ��
		{
			if (a[e.vno][j] < INF && e.length + a[e.vno][j] < dist[j])//����㵽���j�ľ��벻Ϊ����󣬲���С����ǰ��ʼ�ڵ㵽���j�ľ���
				//�������������֦
			{
				e1.vno = j;
				e1.length = e.length + a[e.vno][j];
				dist[j] = e1.length;
				::prev[j] = e.vno;//������һ�����
				que.push(e1);
			}
		}
	}
}
void dispapath(int v, int i)//������ʼ���͵ִ�Ľ��
{
	vector<int> path;//������ʼ��㵽���i��·��
	if (v == i)
	{
		return;
	}
	if (dist[i] == INF)
	{
		cout << "���" << v << "�����" << i << "û��·��" << endl;
	}
	else
	{
		cout << "���" << v << "�����" << i << "��·��Ϊ��";
		path.push_back(i);//�����i����·��
		int k = ::prev[i];//�����i��һ��������·��
		path.push_back(k);
		while (k != v)
		{
			k = ::prev[k];
			path.push_back(k);
		}
		for (int j = path.size() - 1; j >= 0; j--)//���·��
		{
			cout << path[j] << " ";
		}
		cout << endl;
	}
}
void dispallpath(int v)
{
	for (int i = 0; i < n; i++)
	{
		dispapath(v, i);
	}
}
int main()
{
	memset(dist, INF, sizeof(dist));
	memset(a, INF, sizeof(a));
	n = 6;//6�����
	for (int j = 0; j < n; j++)
	{
		a[j][j] = 0;//��㵽�Լ��ľ���Ϊ��
	}
	//������֮��ľ���
	addedge(0, 2, 10);
	addedge(0, 4, 30);
	addedge(0, 5, 100);
	addedge(1, 2, 4);
	addedge(2, 3, 50);
	addedge(4, 3, 20);
	addedge(4, 5, 60);
	addedge(3, 5, 10);
	//Ѱ�����·��
	dfs(v);
	cout << "����·��Ϊ��" << endl;
	dispallpath(v);
}