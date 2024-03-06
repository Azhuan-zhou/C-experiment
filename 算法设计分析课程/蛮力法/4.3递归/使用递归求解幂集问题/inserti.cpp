#include"head.h"
void inserti(vector<vector<int>> &ps, int i)
{
	vector<vector<int>> ps1;
	vector<vector<int >>::iterator it;
	ps1 = ps;
	for (it = ps1.begin(); it != ps1.end(); ++it)//在原来的集合插入数字i
	{
		(*it).push_back(i);
	}
	for (it = ps1.begin(); it != ps1.end(); ++it)//将新集合与原集合合并
	{
		ps.push_back(*it);
	}

}
