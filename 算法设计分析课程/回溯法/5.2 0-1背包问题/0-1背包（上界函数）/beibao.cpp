#include<iostream>
#define N 4
using namespace std;
int W = 6;
struct object
{
    int no;//序号
    int w;//质量
    int v;//价值
    int p;//单位质量的价值
};
object A[N] = { {1,5,4,0.8},{2,3,4,1.3},{3,2,3,1.5},{4,1,1,1}};//物品
int x[N];
int maxv = 0, maxw = 0;
void dispsolution()//输出结果
{
	cout << "分配方案：" << endl;
	for (int i = 0; i < N; i++)
	{
		if (x[i] == 1)
		{
			cout << "第" << A[i].no << "个物品装入背包，重量为" << A[i].w << "kg" << endl;
		}
	}
	cout << "总重量：" << maxw << ",总价值：" << maxv << ".";
}
int bound(int i, int tw, int tv)
{
	i++;//不选择当前节点的物品
	while (i < N && tw + A[i].w <= W)//上界函数：当前的质量与其后选择物品的质量和小于
	{
		tw += A[i].w;
		tv += A[i].v;
		i++;
	}
	if (i < N)
	{
		return  tv + (W - tw) * A[i].p;
	}
	else
	{
		return tv;
	}
}
void fun(int i, int tw, int tv, int op[])//rw为选择i次后，剩下第i+1到N个物品的总总量
{
	if (i == N)//所有物品都抉择过后
	{
		maxv = tv;//传递最大价值
		maxw = tw;//传递总重量
		for (int j = 0; j < N; j++)
		{
			x[j] = op[j];
		}
	}
	else
	{
		//选择将第i个物品装入背包中
		if (tw + A[i].w <= W)//加上第i个物品后总重量还是小于上限质量
		{
			op[i] = 1;
			fun(i + 1, tw + A[i].w, tv + A[i].v, op);
		}
		//不选择将第i个物品装入背包中
		if (bound(i,tw,tv)>maxv)//当不选择第i个物品后，后续的能选上的物品的总重量不仅小于上限质量，其总价值大于当先的最大价值
		{
			op[i] = 0;
			fun(i + 1, tw, tv, op);
		}
	}
}
int main()
{
	int op[N];
	fun(0, 0, 0, op);
	dispsolution();
}