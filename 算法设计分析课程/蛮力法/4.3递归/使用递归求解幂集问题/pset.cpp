#include"head.h"
void pset(int i, int n, vector<vector<int>> &ps)
{
	if (i <= n)//����������ִ���nʱ���ٵݹ�
	{
		inserti(ps,i);
		pset(i + 1, n, ps);
	}
}