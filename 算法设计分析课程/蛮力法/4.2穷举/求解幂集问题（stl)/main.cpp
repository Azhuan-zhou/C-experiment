#include"head.h"
int main()
{
	int n=4;
	vector<vector<int>>ps;
	vector<vector<int>>::iterator it1;
	vector<int>::iterator it2;
	pset(n,ps);
	for (it1 = ps.begin(); it1 != ps.end(); ++it1)
	{
		cout << " { ";
		for (it2 = (*it1).begin(); it2 != (*it1).end(); ++it2)
		{
			cout << " " << *it2 << " ";
		}
		cout << " } " << endl;
	}
}