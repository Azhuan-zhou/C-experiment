#include"head.h"
void print(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << setw(4) << a[i];
	}
	cout << endl;
}