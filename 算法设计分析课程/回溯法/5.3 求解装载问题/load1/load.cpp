#include<iostream>
#define N 5
using namespace std;
int w[] = { 5,2,6,4,3 };
int W = 10;
int x[N];
int maxw = 0, maxv = 0;
void dispsolution()//输出结果
{
	cout << "分配方案：" << endl;
	for (int i = 0; i < N; i++)
	{
		if (x[i] == 1)
		{
			cout << "第" << i + 1 << "个物品装入背包，重量为" << w[i] << "kg" << endl;
		}
	}
	cout << "总重量：" << maxw <<  ".";
}
void fun(int i, int tw, int rw, int op[])//从第0到N-1个物品选择，tw是当前所选择物品的总质量，rw是未选择物品的总质量
{
	if (i == N)
	{
		if (tw <= W)
		{
			maxw = tw;
			for (int j = 0; j < N; j++)
			{
				x[j] = op[j];
			}
		}
		
	}
	else
	{
		//左枝
		if (tw + w[i] <= W)
		{
			op[i] = 1;
			fun(i + 1, tw + w[i], rw - w[i], op);
		}
		//右枝
		if (tw + rw - w[i] >= W)
		{
			op[i] = 0;
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
int main()
{
	int op[N];
	fun(0, 0, sum(w), op);
	dispsolution();
}