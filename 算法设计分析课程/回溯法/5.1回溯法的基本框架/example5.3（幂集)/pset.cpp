#include<iostream>
#define MAX 3
using namespace std;
const int a[] = {1,2,3};
const int n = MAX;
void disp(int x[])//根据解向量输出幂集元素
{
	int i;
	cout << " { ";
	for (i = 0; i < n; i++)
	{
		if (x[i] == 1)
		{
			cout << " " << a[i] << " ";
		}		
	}
	cout << " } "<<endl;
}
void pset(int i,int x[])
{
	if (i >= n)
	{
		disp(x);
	}
	else
	{
		x[i] = 0;//左枝不选择该数字
		pset(i + 1, x);
		x[i] = 1;//右枝选择该数字
		pset(i + 1, x);
	}
}
int main()
{
	int x[MAX] = { 0 };
	cout << "求解结果："<<endl;
	pset(0, x);
}
