#include"head.h"
void pset(int n, vector<vector<int>>& ps)
{
	vector<vector<int>>::iterator it1;
	vector<vector<int>>ps1;
	vector<int>s;
	int i;
	ps.push_back(s);
	for (i = 1; i <= n; i++)
	{
		ps1 = ps;
		for (it1 = ps1.begin(); it1 != ps1.end(); ++it1)
		{
			(*it1).push_back(i);
		}
		for (it1 = ps1.begin(); it1 != ps1.end(); ++it1)
		{
			ps.push_back(*it1);
		}
	}
}