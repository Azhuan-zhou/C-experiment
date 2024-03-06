#include"sort.h"
int main()
{
	int a[] = { 0,4,9,1,3,7,5,6 };
	int n, i;
	n = sizeof(a) / sizeof(int);
	cout << "未排序的数组为:" << endl;
	for (i = 0; i < n; i++)
	{
		cout << setw(4) << a[i];
	}
	cout << endl;
	cout << "排序后的数组为:" << endl;
	bubblesort(a, n);
	for (i = 0; i < n; i++)
	{
		cout << setw(4) << a[i];
	}
	return 0;
}
