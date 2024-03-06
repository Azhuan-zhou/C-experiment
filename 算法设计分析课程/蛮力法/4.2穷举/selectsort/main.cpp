#include<iostream>
using namespace std;
void print(int a[], int size);
void selectsort(int a[], int size);
void swap(int* p1, int* p2);
int main()
{
	int a[] = { 2,5,1,7,10,6,9,4,3,8 };
	int size = 10;
	cout << "ÅÅÐòÇ°£º";
	print(a,size);
	cout << "ÅÅÐòºó£º";
	selectsort(a, size);
	print(a, size);
}
void print(int a[],int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		cout << a[i]<<" ";
	}
	cout << endl;
}
void selectsort(int a[],int size)
{
	int i, j;
	int k;
	for (i = 0; i < size; i++)
	{
		k = i;
		for (j = i + 1; j < size; j++)
		{
			if (a[j] < a[k])
			{
				k=j;			
			}
		}
		swap(&a[i], &a[k]);		
	}
}
void swap(int* p1, int* p2)
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}