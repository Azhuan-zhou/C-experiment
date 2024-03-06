#include<iostream>
#define N 3
using namespace std;
int a[N] = { 1,2,3 };
void dispsolution()//输出
{
	cout << " { ";
	for (int i = 0; i < N-1; i++)
	{
		cout << a[i] << ',';
	}
	cout << a[N-1] << " } "<<endl;
}
void swap(int* p1, int* p2)//交换
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void fun(int i,int n)
{
	if (i == n)
	{
		dispsolution();
	}
	else
	{
		for (int j = i; j < n; j++)
		{
			swap(&a[i], &a[j]);
			fun(i + 1, n);
			swap(&a[i], &a[j]);//回溯
		}
	}
}
int main()
{
	cout << "1~3的全排列为：" << endl;
	fun(0, N);
}