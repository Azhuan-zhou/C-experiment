#include"head.h"
int backseq(int s, int t)
{
	int m;
	m = (s + t) / 2;
	if ((s + t) % 2 == 0)
	{
		return m;
	}
	else
	{
		return m + 1;
	}
}
