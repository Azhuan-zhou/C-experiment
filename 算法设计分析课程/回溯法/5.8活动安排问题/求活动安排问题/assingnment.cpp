#include<iostream>
using namespace std;
struct activity
{
	int start;
	int end;
};
const activity a[5] = { {1,3},{4,8},{6,10},{2,5},{3,5} };//活动的起始时间和结束时间
int x[5] = { 1,2,3,4,5 };//解空间向量
int X[5];//存放举办活动最多的解空间向量
const int n = 5;//活动个数
int maxcount = 0;//举办最多活动的个数
void swap(int &a, int &b)//交换
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void disp()//输出
{
	cout << "最优调度方案：" << endl;
	int last = 0;
	for (int j = 0; j < n; j++)
	{
		if (a[X[j] - 1].start >= last)//根据最佳的解向量输出能举办的活动
		{
			last = a[X[j] - 1].end;
			cout << "选取活动" << X[j] << ": [" << a[X[j] - 1].start << "," << a[X[j] - 1].end << ")" << endl;
			
		}
	}
	cout << "安排活动个数：" << maxcount << "个";
}
void fun(int i)
{
	if (i >= n)
	{
		int last = 0;
		int count = 0;
		for (int j = 0; j < n; j++)//计算每一个方案举办活动的个数
		{
			if (a[x[j]-1].start >= last)
			{
				count++;
				last = a[x[j]-1].end;
			}
		}
		if (count > maxcount)//找出能举办活动最多方案
		{
			maxcount = count;
			for (int j = 0; j < n; j++)
			{
				X[j] = x[j];
			}
		}
	}
	else
	{
		for (int j = i; j < n; j++)
		{
			swap(x[i], x[j]);//交换
			fun(i + 1);
			swap(x[i], x[j]);//回溯

		}
	}
}
int main()
{
	fun(0);
	disp();
}