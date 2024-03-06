#include<iostream>
#define N 5
using namespace std;
//全局变量
int w[N] = { 0,5,3,2,1 };//重量
int v[N] = { 0,4,4,3,1 };//价值
const int W = 6;//重量上限
int maxV = 0;//最大价值
int maxW = 0;
int x[N];
void dispsolution()//输出结果
{
	cout << "分配方案："<<endl;
	for (int i = 0; i < N; i++)
	{
		if (x[i] == 1)
		{
			cout << "第" << i + 1 << "个物品装入背包，重量为" << w[i] << "kg" << endl;
		}
	}
	cout << "总重量：" << maxW << ",总价值：" << maxV << ".";
}
void fun(int i, int tw, int tv, int op[])
{
	if (i == N)//所有物品都抉择过后
	{
		if (tw <= W && tv >= maxV)//能装入背包的约束条件
		{
			maxV = tv;//传递最大价值
			maxW = tw;//传递总重量
			for (int j = 0; j < N; j++)
			{
				x[j] = op[j];
			}
		}
	}
	else
	{
		//选择将第i个物品装入背包中
		op[i] = 1;
		fun(i + 1, tw + w[i], tv + v[i], op);
		//不选择将第i个物品装入背包中
		op[i] = 0;
		fun(i + 1, tw, tv, op);
	}
}
int main()
{
	int op[N];
	fun(0, 0, 0, op);
	dispsolution();
}