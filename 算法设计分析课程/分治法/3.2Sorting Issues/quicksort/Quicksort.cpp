#include"БъЭЗ.h"
int partition(int a[], int s, int t);
void Quicksort(int a[], int s, int t)
{
	if (s < t)
	{
		int i = partition(a, s, t);
		Quicksort(a, s, i - 1);
		Quicksort(a, i + 1, t);
	}
}