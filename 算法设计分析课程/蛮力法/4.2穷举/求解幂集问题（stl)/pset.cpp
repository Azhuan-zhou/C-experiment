#include"head.h"
void pset(int n,vector<vector<int>>&ps)
{
	vector<vector<int>> ps1;
	vector<vector<int>> ::iterator it;
	vector<int> s;
	int i;
	ps.push_back(s);
	for (i = 1; i <= n; i++)
	{
		ps1 = ps;
		for (it = ps1.begin(); it != ps1.end(); ++it)
		{
			(*it).push_back(i);
		}
		for (it = ps1.begin(); it != ps1.end(); ++it)
		{
			ps.push_back(*it);
		}

	}

}