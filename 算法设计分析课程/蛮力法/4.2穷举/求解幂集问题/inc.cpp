#include"head.h"
void inc(int b[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (b[i] == 1)
		{
			b[i] = 0;
		}
		else
		{

			b[i] = 1;
			break;
		}
	}
}
  