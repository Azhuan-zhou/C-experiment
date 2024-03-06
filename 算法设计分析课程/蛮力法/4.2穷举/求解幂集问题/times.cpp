#include"head.h"
int times(int n)
{
	int i, k=1;
	for (i = 0; i < n; i++)
	{
		k = k * 2;
	}
	return k;
}