#include"head.h"
void insert(vector<int>&s, int i, vector<vector<int>>&ps1)
{
	vector<int> s1;
	vector<int>::iterator it;
	for (int j = 0; j < i; j++)
	{
		s1 = s;
		it = s1.begin()+j;//�ڵ�it��λ��ǰ����i
		s1.insert(it, i);
		ps1.push_back(s1);
	}
}