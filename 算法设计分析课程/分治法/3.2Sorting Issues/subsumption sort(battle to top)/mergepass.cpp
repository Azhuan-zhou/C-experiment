#include"head.h"
void mergepass(int a[], int length, int n)
{
	int i;
	for (i = 0; i + 2 * length - 1 < n; i = i + 2 * length )
	{
		merge(a, i, i + length - 1, i + 2 * length - 1);
	}
	if (i + length - 1 < n)
	{
		merge(a, i, i + length - 1, n - 1);
	}
}
