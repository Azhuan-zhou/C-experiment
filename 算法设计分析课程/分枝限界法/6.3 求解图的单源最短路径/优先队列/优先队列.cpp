#include<iostream>
#include<vector>
#include<queue>
#define INF 0x3f3f3f3f
#define MAX 50
using namespace std;
int n;//结点个数
int dist[MAX];//储存结点间的距离
int prev[MAX];//储存上一个结点
int v = 0;//起始结点编号
int a[MAX][MAX];//邻接矩阵
struct Nodetype
{
	int vno;//结点编号
	int length;//起始节点到该结点的 路径长度
	bool operator<(const Nodetype& e)const
	{
		return length > e.length;//队列中小的优先出去
	}
};
void addedge(int i, int j, int w)
{
	a[i][j] = w;//结点i到结点j的距离为w
}
void dfs(int v)
{
	Nodetype e;//根结点
	Nodetype e1;//儿子结点
	priority_queue<Nodetype> que;//存放儿子结点的队列
	e.vno = 0;
	e.length = 0;
	dist[v] = 0;
	que.push(e);
	while (!que.empty())
	{
		e = que.top();//将队列的第一个元素作为根节点扩展
		que.pop();//删去根节点
		for (int j = 0; j < n; j++)//将所有结点遍历一遍
		{
			if (a[e.vno][j] < INF && e.length + a[e.vno][j] < dist[j])//根结点到结点j的距离不为无穷大，并且小与先前起始节点到结点j的距离
				//不满足条件则剪枝
			{
				e1.vno = j;
				e1.length = e.length + a[e.vno][j];
				dist[j] = e1.length;
				::prev[j] = e.vno;//储存上一个结点
				que.push(e1);
			}
		}
	}
}
void dispapath(int v, int i)//传入起始结点和抵达的结点
{
	vector<int> path;//储存起始结点到结点i的路径
	if (v == i)
	{
		return;
	}
	if (dist[i] == INF)
	{
		cout << "结点" << v << "到结点" << i << "没有路径" << endl;
	}
	else
	{
		cout << "结点" << v << "到结点" << i << "的路径为：";
		path.push_back(i);//将结点i放入路径
		int k = ::prev[i];//将结点i上一个结点放入路径
		path.push_back(k);
		while (k != v)
		{
			k = ::prev[k];
			path.push_back(k);
		}
		for (int j = path.size() - 1; j >= 0; j--)//输出路径
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
	n = 6;//6个结点
	for (int j = 0; j < n; j++)
	{
		a[j][j] = 0;//结点到自己的距离为零
	}
	//输入结点之间的距离
	addedge(0, 2, 10);
	addedge(0, 4, 30);
	addedge(0, 5, 100);
	addedge(1, 2, 4);
	addedge(2, 3, 50);
	addedge(4, 3, 20);
	addedge(4, 5, 60);
	addedge(3, 5, 10);
	//寻找最短路径
	dfs(v);
	cout << "最优路径为：" << endl;
	dispallpath(v);
}