#include<iostream>
#include<queue>
#define MAX 20
#define INF 0x3f3f3f3f
using namespace std;
int t = 1;//结点编号
int n = 4;//加工的物品个数
int M1[] = { 0,5,12,4,8 };//物品在M1加工的时间
int M2[] = { 0,6,2,14,7};//物品在M2加工的时间
int mint = INF;//加工最短时间
int bestx[MAX];//最优解向量
struct Nodetype
{
	int no;//结点编号
	int f1;//物品在M1加工的总时间
	int f2;//物品在M2加工的总时间
	bool object[MAX];//object[i]=true 表示第i个物品已经被加工
	int x[MAX];// x[i]=j 表示第i步加工j物品
	int i;//步骤编号
	int lb;//最小下界
	bool operator <(const Nodetype& e)const//重载运算符
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
	priority_queue<Nodetype> que;//优先队列
	Nodetype e;//根节点
	Nodetype e1;//子节点
	//起始结点初始化
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
		e = que.top();//保存根节点
		que.pop();//删去根节点
		//扩展结点
		e1.i = e.i + 1;
		for (int j = 1; j <= n; j++)//遍历所有的物品
		{
			if (e.object[j] == true)//如果物品j已经分配过了，则进入下一次循环
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

			//当达到叶子结点时，判断储存最优解
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
			if (e1.lb < mint)//当最小下界小于目前的最优值时，说明沿着该路可能找到一个比目前更优的值
			{
				que.push(e1);
			}
		}
	}
}
int main()
{
	bfs();
	cout << "最优加工方案为：" << endl;
	for (int j = 1; j <= n; j++)
	{
		cout << "第" << j << "步加工" << bestx[j] << endl;
	}
	cout << "最小加工时长为：" << mint;
}