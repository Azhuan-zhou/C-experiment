#include"head.h"
void perm(int n, vector<vector<int >>& ps)
{
	vector<vector<int>> ps1;
	vector<vector<int>>::iterator it;
	vector<int>s;
	s.push_back(1);
	ps.push_back(s);
	for (int i = 2; i <= n; i++)
	{
		ps1.clear();
		for (it = ps.begin(); it != ps.end(); ++it)
		{
			insert(*it, i, ps1);
		}
		ps = ps1;
	}
}