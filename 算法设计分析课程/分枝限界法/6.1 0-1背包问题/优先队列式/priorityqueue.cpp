#include<iostream>
#include<queue>
#define N 10
using namespace std;
int n = 3;//物品数量
int w[] = { 0,16,15,15 };//物品重量
int W = 30;//背包上限重量；
int v[] = { 0,45,25,25 };//物品价值
int bestw=0;//最优方案的重量
int bestv=0;//最优方案的价值
int bestx[N];//最优方案的解向量
int number = 0;
struct Nodetype
{
	int i;//搜索层次
	int no;//结点序号，从1开始
	int w;//结点背包中的重量
	int v;//结点背包中的价值
	int x[N];//结点的解向量
	double ub;//结点的上界
	bool operator<(const Nodetype& e) const
	{
		return ub < e.ub;//重载关系运算符“<”,使用优先队列
	}
};
void bound(Nodetype &e)//上界函数
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
void Enqueue(Nodetype e, priority_queue<Nodetype>& qu)//将结点放入队列的函数
{
	if (e.i == n)//达到叶子结点时不放入队列
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
	else//没有达到叶子结点放入
	{
		qu.push(e);
	}
}
void fun()
{
	Nodetype e;//根节点
	Nodetype e1;//左孩子结点
	Nodetype e2;//右孩子结点
	priority_queue<Nodetype> qu;
	//对根节点初始化
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
		//左枝：选择下一个结点的物品
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
		//右枝：不选择下一个结点的物品
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
	cout << "分支界限的优先队列解决0-1背包问题：" << endl;
	cout << "X=[ ";
	for (int j = 1; j <= n; j++)
	{
		cout << bestx[j] << " ";
	}
	cout << "],物品的价值为："<<bestv;

}