#include"head.h"
void insert(int i, vector<int>&s, vector<vector<int>>&ps1)//对集合s插入数字i
{
	vector<int>::iterator it;
	vector<int> s1;
	for (int j = 0; j < i; j++)
	{
		s1 = s;
		it = s1.begin()+j;
		s1.insert(it, i);
		ps1.push_back(s1);
	}
}