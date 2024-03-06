#include"head.h"
void pset(int i, int n, vector<vector<int>> &ps)
{
	if (i <= n)//当插入的数字大于n时不再递归
	{
		inserti(ps,i);
		pset(i + 1, n, ps);
	}
}