#include<iostream>
using namespace std;
struct Time
{
	int M1;
	int M2;
};
int n = 4;
Time T[4] = { {5,6},{12,2},{4,14},{8,7} };//M1和M2对不同任务运作的时间
int bestx[4];//存放总时间最短的分配方案
int x[] = { 1,2,3,4 };//存放当前的调度方案
int bestT=9999999;//最短时间
int f1=0;//M1机器所使用的时间
int f2[5] = {0};//M1加工完成后，M2所加工的时间之和
void swap(int &a,int &b)//交换
{
	int temp = a;
	a = b;
	b = temp;
}
void disp()//输出
{
	cout << "最短时间为：" << bestT<<",最优调度方案为：";
	for (int j = 0; j < n; j++)
	{
		cout << bestx[j] << " ";
	}
}
void fun(int i)
{

	if (i == n)
	{
		if (f2[i+1] < bestT)//当找到最优的方案时，总生产的时间最小时
		{
			bestT = f2[i];//存放最短时间
			for (int j = 0; j < n; j++)
			{
				bestx[j] = x[j];//存放分配方案
			}
		}
	}
	else
	{
		for (int j = i; j < n; j++)
		{
			swap(x[i], x[j]);
			f1 += T[x[i] - 1].M1;//M1加工所需要的时间
			f2[i + 1] = max(f1, f2[i]) + T[x[i]].M2;//M1加工完在M2上所加工的时间
			//第一种情况：当在M1加工一件产品的时间大于M2加工上一个产品的时间时，总时间为M1加工完这个产品的时间加上这件产品在M2的时间
			//第二种情况：当在M1加工一件产品的时间小于M2加工上一个产品的时间时，总时间为M2加工完上一个产品的时间加上这件产品在M2的时间
			if (f2[i + 1] < bestT)
			{
				fun(i + 1);
			}
			f1 -= T[x[i] - 1].M1;
			swap(x[i], x[j]);
		}
	}

}
int main()
{
	fun(0);
	disp();
}