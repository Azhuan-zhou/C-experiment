#include"БъЭЗ.h"
int partition(int a[], int s, int t)
{
	int temp = a[s];
	int i = s;
	int j = t;
	int k;
	while (i != j)
	{
		while (i < j && a[j] >= temp)
			j--;
		while (i < j && a[i] <= temp)
			i++;
		k = a[i];
		a[i]=a[j];
		a[j] = k;
	}
	a[s] = a[i];
	a[i] = temp;
	return i;
}