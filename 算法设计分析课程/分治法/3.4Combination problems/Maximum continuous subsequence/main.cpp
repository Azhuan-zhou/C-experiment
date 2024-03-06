#include"head.h"
int main()
{
	int a[] = { -2,11,-4,13,-5,-2 };
	int n = 6,k;
	k = maxsubsum(a, 0, n - 1);
	cout << "最大连续子序列的和为:" << k << endl;
}