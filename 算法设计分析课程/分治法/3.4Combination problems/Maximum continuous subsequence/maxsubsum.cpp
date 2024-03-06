#include"head.h"
int maxsubsum(int a[], int s, int t)//将问题分解为左边序列，右边序列和中间序列
{
	int maxrightsub, maxleftsub;
	int mid = (s + t) / 2;
	maxrightsub = maxsubsum(a, mid + 1, t);
	maxleftsub = maxsubsum(a, s, mid);
	int i,j,m=0,n=0;
	int maxleftbordersum = 0;
	int maxrightbordersum = 0;
	if (s == t)
	{
		return a[s];
	}
	for (i = mid; i >= s; i--)
	{
		m += a[i];
		if (m > maxleftbordersum)
		{
			maxleftbordersum = m;
		}		
	}
	for (j = mid + 1; j <= t; j++)
	{
		n += a[j];
		if (n > maxrightbordersum)
		{
			maxrightbordersum = n;
		}
	}
	return max(maxleftsub, maxrightsub, (maxleftbordersum + maxrightbordersum));
}