#include<iostream>
using namespace std;
void print(int a[], int size);
void bubblesort(int a[], int size);
void swap(int* p1, int* p2);
int main()
{
	int a[] = { 2,5,1,7,10,6,9,4,3,8 };
	int size = 10;
	cout << "排序前：";
	print(a, size);
	cout << "排序后：";
	bubblesort(a, size);
	print(a, size);
}
void print(int a[], int size)//打印
{
	int i;
	for (i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void bubblesort(int a[], int size)//冒泡排序
{
	int i,j;
	for (i = size-1;i>=0;i--)//从最后一个元素开始，大的元素向后移动
	{ 
		for (j =0 ;j <i ; j++)
		{
			if (a[i] < a[j])
			{
				swap(&a[i], &a[j]);
			}
		}
	}
}
void swap(int* p1, int* p2)//交换
{
	int temp;
	temp = *p1;
		* p1 = *p2;
		* p2 = temp;
}
