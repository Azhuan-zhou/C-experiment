#include"head.h"
void mergesort(int a[], int n)
{
	int length;
	for (length = 1; length < n; length = 2 * length)
	{
		mergepass(a, length, n);
	}
}