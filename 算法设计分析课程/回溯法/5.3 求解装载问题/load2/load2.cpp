#include<iostream>
#define N 3
using namespace std;
int w[] = { 10,40,40 };//货物的重量
int c1 = 50, c2 = 50;//分别为两艘轮船的最大装载量
int x[N];//解空间向量
int maxw = 0;//第一艘轮船最大装载货物的量
void dispsolution()//输出结果
{
	cout << "分配方案：" << endl;
	for (int i = 0; i < N; i++)
	{
		if (x[i] == 1)
		{
			cout << "第" << i + 1 << "个集装箱装入第一艘轮船，重量为" << w[i] << "t" << endl;
		}
		else
		{
			cout << "第" << i + 1 << "个集装箱装入第二艘轮船，重量为" << w[i] << "t" << endl;
		}
	}
}
void fun(int i, int tw, int rw, int op[])//从第0到N-1个物品选择，tw是当前所选择物品的总质量，rw是未选择物品的总质量
{
	if (i == N)//遍历所有集装箱后
	{
		if (tw >= maxw)
		{
			maxw = tw;//如果总重量大于最优的重量，则保存它
			for (int j = 0; j < N; j++)
			{
				x[j] = op[j];//保存解向量
			}
		}

	}
	else
	{
		//左枝
		if (tw + w[i] <= c1)
		{
			op[i] = 1;//选择
			fun(i + 1, tw + w[i], rw - w[i], op);
		}
		//右枝
		if (tw + rw - w[i] >= maxw)
		{
			op[i] = 0;//不选择
			fun(i + 1, tw, rw - w[i], op);
		}
	}
}
int sum(int a[])//求和
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += a[i];
	}
	return sum;
}
bool solve()
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (x[i] == 0)
		{
			sum += w[i];
		}
	}
	if (sum <= c2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int op[N];
	fun(0, 0, sum(w), op);
	if (solve())
	{
		cout << "存在一个装载方案：" << endl;
		dispsolution();
	}
	else
	{
		cout << "不存在一个装载方案";
	}
}