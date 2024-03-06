#include"head.h"
int midnum(int a[], int s1, int t1, int b[],int s2,int t2)
{
	if (s1 == t1 && s2 == t2)
	{
		if (a[s1] < b[s2])
		{
			return a[s1];
		}
		else
		{
			return b[s2];
		}
	}
	else
	{
		int m1 = frontseq(s1, t1);
		int m2 = frontseq(s2, t2);
		if (a[m1] == b[m2])
		{
			return a[m1];
		}
		else
		{
			if (a[m1] < b[m2])
			{
				m1 = backseq(s1, t1);
				midnum(a, m1, t1, b, s2, m2);
			}
			else
			{
				m2 = backseq(s2, t2);
				midnum(a, s1, m1, b, m2, t2);			
			}
		}
	}
}