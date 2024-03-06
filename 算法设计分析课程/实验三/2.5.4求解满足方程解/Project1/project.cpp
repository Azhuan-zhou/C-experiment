#include<iostream>
using namespace std;
int a[] = { 1,2,3,4,5 };
int n = 5;
int Count=1;
void swap(int& a, int& b)//交换位置
{
	int temp=a;
	a = b;
	b = temp;
}
void disp()//输出解
{
	cout << "第" << Count << "个解：";
	cout << a[0] << "*" << a[1] << "-" << a[2] << "*" << a[3] << "+" << a[4] << "=1" << endl;
}
void dfs(int i)//深度搜索。第i层
{
	if (i==n)//当到达叶子结点
	{
		if (a[0] * a[1] - a[2] * a[3] - a[4] == 1)
		{
			disp();
			Count++;
		}
	}
	else
	{
		for (int j = i; j < n; j++)//第i层，从第i个元素开始，依次和后面的元素交换位置
		{
			swap(a[i], a[j]);//交换
			dfs(i + 1);//深入
			swap(a[i], a[j]);//回溯
		}
	}
}
int main()
{
	cout << "求解结果：" << endl;
	dfs(0);
}