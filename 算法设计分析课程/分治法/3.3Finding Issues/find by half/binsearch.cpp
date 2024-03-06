#include"head.h"
int binsearch(int a[], int low, int high,int k)
{
	if (low <= high)
	{
		int mid = (low + high) / 2;
		if (a[mid] == k)
		{
			return mid;
		}
		else
		{
			if (a[mid] > k)
			{
				binsearch(a, low, mid - 1, k);
			}
			else
			{
				binsearch(a, mid + 1, high, k);
			}
		}
		
	}
	else
	{
		return -1;
	}
}