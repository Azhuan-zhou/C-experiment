#include"head.h"
void find(int a[], int low, int high, int& max1, int& max2)
{
	if (low == high)
	{
		max1 = a[low];
		max2 = INT_MIN;
	}
	else if (high - low == 1)
	{
		max1 = a[high];
		max2 = a[low];
	}
	else
	{
		int mid = (low + high) / 2;
		int lmax1, lmax2;
		int rmax1, rmax2;
		find(a, low, mid, lmax1, lmax2);
		find(a, mid + 1, high, rmax1, rmax2);
		if (lmax1 >= rmax1)
		{
			max1 = lmax1;
			max2 = max(rmax1,lmax2);
		}
		else
		{
			max1 = rmax1;
			max2 =max( lmax1,rmax2);
		}
	}
}