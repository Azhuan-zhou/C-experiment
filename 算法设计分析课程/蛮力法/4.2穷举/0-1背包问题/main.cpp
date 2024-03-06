#include"head.h"
int main()
{
	vector<vector<int>>ps;
	vector<vector<int>>::iterator it1;
	vector<int>::iterator it2;
	int n = 4, W = 6;
	int w[] = { 5,3,2,1 };
	int v[] = { 4,4,3,1 };
	pset(n, ps);
	cout << "0-1背包问题的求解方案：" << endl;
	knap(w, v, W, ps);
}