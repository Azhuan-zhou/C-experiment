#include"head.h"
int find(int a[], int n, int b[], int m, int k)
{
	if (n > m)
	{
		return find(b, m, a, n, k);
	}
	if (n == 0)
	{
		return b[k - 1];
	}
	if (k == 1)
	{
		if (a[0] > b[0])
			return b[0];
		else
			return a[0];
	}
	int numa;//还是折半查找的思想
	if (n >= k / 2)
	{
		numa = k / 2;
	}
	else
	{
		numa = n;
	}
	int numb = k - numa;
	if (a[numa - 1] == b[numb -1])
	{
		return b[numb - 1];
	}
	else
	{
		if (a[numa - 1] < b[numb - 1])
		{
			return find(&a[numa], n - numa, b, m, k - numa);
		}
		else
		{
			return find(a, n, &b[numb], m - numb, k - numb);
		}
	}
}