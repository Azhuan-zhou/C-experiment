#include"head.h"
void pset(int a[], int b[], int n)
{
	int i, j;
	int k = times(n);
	for (i = 0; i < k; i++)
	{
		cout << "{ ";
		for (j = 0; j < n; j++)
		{
			if (b[j] == 1)
			{
				cout << a[j]<<" ";
			}
		}
		inc(b, n);
		cout << " } ";
	}
}