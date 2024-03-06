#include"sort.h"
void bubblesort(int *p, int n)
{
	int i, j, t;
	int* p2 = p;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (*p > *(p+1))
			{
				t = *p;
				*p = *(p+1);
				*(p+1) = t;
			}
			p++;
		}
		p = p2;
	}
}
