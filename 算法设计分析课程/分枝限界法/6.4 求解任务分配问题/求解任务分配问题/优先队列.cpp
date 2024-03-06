#include<iostream>
#include<queue>
#define INF 0x3f3f3f3f
#define MAX 50
using namespace std;
int cost[MAX][MAX] = { {0},{0,9,2,7,8},{0,6,4,3,7},{0,5,8,1,8},{0,7,6,9,4} };//第i个任务分配给第j人的成本
int n = 4;//人数
int bestx[MAX];//最优解向量
int bestc = INF;//最优成本
int t = 1;//结点编号
struct Nodetype
{
	int cost;//结点的成本
	int lb;//结点的下界
	int i;//任务编号
	int no;//结点编号
	bool worker[MAX];//人员是否分配了任务的布尔数组
	int x[MAX];//解向量
	bool operator <(const Nodetype& e) const
	{
		return lb > e.lb;
	}
};
void bound(Nodetype& e)
{
	int mincost=e.cost;
	for (int i = e.i+1; i <= n; i++)//从根结点的下一个任务开始到第n个任务结束
	{
		int k = INF;
		for (int j = 1; j <= n; j++)//遍历所有的员工
		{
			if (e.worker[j] == false && cost[i][j] < k)//没有分配任务的员工而且成本最低的
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
	priority_queue<Nodetype> que;//优先队列
	Nodetype e;//根节点
	Nodetype e1;//子节点
	//起始结点
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
	que.push(e);//将起始结点放入队列中欧你
	while (!que.empty())
	{
		e = que.top();//根据最小的lb确定根节点扩展
		que.pop();//去除队列中的根结点
		//储存最优解
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
		for (int j = 1; j <= n; j++)//遍历所有的工人
		{
			if (e.worker[j])
			{
				continue;
			}
			for (int i1 = 1; i1 <= n; i1++)//将根节点的解向量和bool数组赋值到子节点
			{
				e1.worker[i1] = e.worker[i1];
				e1.x[i1] = e.x[i1];
			}
			e1.worker[j] = true;
			e1.x[e1.i] = j;
			e1.no = t++;
			e1.cost =e.cost + cost[e1.i][j];
			bound(e1);
			//剪枝
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
	cout << "最佳任务安排：" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << "第" << i << "个任务安排给" << "第" << bestx[i] << "个人" << endl;
	}
	cout << "总成本为：" << bestc;
	
}