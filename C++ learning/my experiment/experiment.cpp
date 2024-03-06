#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int a[] = { 5,3,2,0,9,3,4,1,7 };
int n = sizeof(a) / sizeof(int);
int maxs = 0;
int minn = 10000;
void disp(int m, int k)
{
	for (int i = m; i <= k; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
int sum(int m, int k)
{
	int sum=0;
	for (int i = m; i <= k; i++)
	{
		sum += a[i];
	}
	return sum;
}
int parition(int start, int end)
{
	int i=start, j=end;
	int first = a[start];//记录数组第一个元素
	while (i != j)
	{
		while (a[j] >= first && j>i)
		{
			j--;
		}
		while (a[i] <= first && i < j)
		{
			i++;
		}
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	a[start] = a[i];
	a[i] = first;
	int curs, curn;
	curs = (int)fabs(sum(0, i)-sum(i + 1, n-1));
	curn = (int)fabs(2 * i + 1 - n);
	if (curs > maxs)
	{
		cout << curs;
		maxs = curs;
	}
	if (curn < minn)
	{
		minn = curn;
	}
	return i;
}
void quicksort(int start,int end)
{
	int i = start;
	int j = end;
	if(i<j)
	{
		int i = parition(start, end);
		quicksort(start,i-1);
		quicksort(i+1, end);
	}
}
int main()
{
	cout << "排序前：";
	disp(0, n-1);
	quicksort(0, n - 1);
	cout << "排序后：";
	disp(0,n-1);
	cout << "min(|n1-n2|)=" << minn << ",max(|s1-s2|)=" << maxs<<endl;
}