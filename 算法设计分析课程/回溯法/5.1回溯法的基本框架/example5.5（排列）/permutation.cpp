#include<iostream>
#define N 3
using namespace std;
int a[N] = { 1,2,3 };
void dispsolution()//���
{
	cout << " { ";
	for (int i = 0; i < N-1; i++)
	{
		cout << a[i] << ',';
	}
	cout << a[N-1] << " } "<<endl;
}
void swap(int* p1, int* p2)//����
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
			swap(&a[i], &a[j]);//����
		}
	}
}
int main()
{
	cout << "1~3��ȫ����Ϊ��" << endl;
	fun(0, N);
}