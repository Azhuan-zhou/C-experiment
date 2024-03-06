#include<iostream>
#include<queue>
#define N 2001
using namespace std;
int n = 3;//物品个数
int w[] = {0,16,15,15};//物品重量
int v[] = { 0,45,25,25 };//物品价值
int bestw = 0;//放入物品的最大重量
int bestv = 0;//放入物品的最优价值
int W = 30;//背包上限重量
int bestx[N];//存放最佳方案
int Number = 0;
struct Nodetype
{
	int i;//当前结点在搜索空间的层次
	int No;//结点序号，从1开始；
	int w;//结点的重量
	int v;//结点的价值
	int x[N];//结点的解空间
	int ub;//结点的上界
};
void bound(Nodetype& e)
{
	int i = e.i+1;
	int sumw = e.w;
	int sumv = e.v;
	while (sumw + w[i] <= W && i <= n)//重量小于背包上限并且搜索层次小于等于3
	{
		sumw += w[i];//计算出当前结点加上剩余满足上述条件的物品重量
		sumv += v[i];//计算出当前结点加上剩余满足上述条件的物品价值
		i++;
	}
	if (i <= n)
	{
		 e.ub = sumv + (W - sumw) * (v[i] / w[i]);//如果第i+1个物品放不下，重量相比于W有剩余，则按照剩下重量乘以该物品单位重量放入，上界sumv + (W - sumw) * (v[i] / w[i]
		 //因为无论时哪个第i+1个后面的物品放入，加入后背包后的总重量总会小于这个值
	}
	else
	{
		e.ub = sumv;//当所有的搜索层次都遍历完后，上界就等于sumv
	}
}
void Enqueue(Nodetype e,queue<Nodetype> &qu)
{
	if (e.i == n)//当搜索层次达到叶子结点时，结点不放入队列
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
		qu.push(e);//当没有达到叶子节点时将结点放入队列
	}
}
void fun()
{
	Nodetype e;//根节点
	Nodetype e1;//左扩展结点
	Nodetype e2;//右扩展结点
	queue<Nodetype> qu;
	//设置起始结点
	e.i = 0;//起始节点搜索层次
	e.No = Number++;//起始结点序号
	e.w = 0;//起始结点重量
	e.v = 0;//起始结点价值
	for (int j = 0; j <= n; j++)
	{
		e.x[j] = 0;//起始结点的解空间
	}
	bound(e);//起始结点的上界
	qu.push(e);//将起始结点放入队列
	while (!qu.empty())//当队列不为空时
	{
		e = qu.front();//根节点
		qu.pop();//将根结点从队列中删去
		//左枝（e1为拓展结点）
		if (e.w + w[e.i + 1] <= W && e.i <= n)//不满足则剪枝
		{
			e1.v = e.v + w[e.i + 1];//加上下一个物品的价值
			e1.w = e.w + w[e.i + 1];//加上下一个物品的重量
			e1.i = e.i + 1;//搜索层次加一
			e1.No = Number++;//结点序号加一
			for (int j = 0; j <= e.i; j++)
			{
				e1.x[j] = e.x[j];//复制根节点的解空间
			}
			e1.x[e1.i] = 1;//由于选择了下一个物品，该位置的解空间改为1
			bound(e1);
			Enqueue(e1, qu);//将左拓展结点放入队列
		}
		//右枝（e2为拓展结点）
		e2.v = e.v ;//不加上下一个物品的价值
		e2.w = e.w ;//不加上下一个物品的重量
		e2.i = e.i + 1;//搜索层次加一
		e2.No = Number++;//结点序号加一
		for (int j = 0; j <= e.i; j++)
		{
			e2.x[j] = e.x[j];//复制根节点的解空间
		}
		e2.x[e2.i] = 0;//由于没有选择下一个物品，该位置的解空间改为0
		bound(e2);
		if (e2.ub > bestv)//当上界大于当前最大价值时才可能存在比最大价值大的方案
		{
			Enqueue(e2, qu);
		}
		
	}
	
}
int main()
{
	fun();
	cout << "分支界限法求解0-1背包问题：" << endl;
	cout << "X=[ ";
	for (int i = 1; i <= n; i++)
	{
		cout << bestx[i] << " ";
	}
	cout << "],总价值为："<<bestv;
}