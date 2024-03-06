#include"head.h"
void mergesort(int a[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		mergesort(a, low, mid);

		mergesort(a, mid + 1, high);

		merge(a, low, mid, high);
	}
}