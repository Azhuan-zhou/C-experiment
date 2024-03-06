#include"head.h"
int quicksort(int a[], int low, int high,int k)
{
	int i = low;
	int j = high;
	int temp=a[low],t;
	if (i < j)
	{
		while (i != j)
		{
			while (j > i && a[j] >= temp)
			{
				j--;
			}
			while (i < j && a[i] <= temp)
			{
				i++;
			}
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		a[low] = a[i];
		a[i] = temp;
		if (i == k)
		{
			return a[i];
		}
		else if (i < k)
		{
			return quicksort(a, i + 1, high, k);
		}
		else
		{
			return quicksort(a, low, i - 1, k);
		}
	}
	else if (i == j && i == k);
	{
		return a[i];
	}
    
}