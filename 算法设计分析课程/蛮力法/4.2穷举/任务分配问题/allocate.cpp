#include"head.h"
void allocate(int n, int &minicost, int &minip,vector<vector<int>>&ps)//����ɱ���͵ķ���
{
	int sumcost=0;
	int c[4][4] = { {9,2,7,8},{6,4,3,7},{5,8,1,8},{7,6,9,4} };//�ɱ�
	perm(n, ps);
	for (int i = 0; i < ps.size(); i++)//��������
	{
		for (int j = 0; j < n; j++)//��Ա
		{
			sumcost += c[j][ps[i][j] - 1];
		}
		if (minicost >= sumcost)
		{
			minicost = sumcost;
			minip = i;
		}
		sumcost = 0;
	}
}