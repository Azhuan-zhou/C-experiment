#include"head.h"
void perm(int n, vector<vector<int>>& ps)//����ȫ��������
{
	vector<vector<int>> ps1;
	vector<int> s;
	vector<vector<int>>::iterator it;
	s.push_back(1);
	ps.push_back(s);
	for (int i = 2; i <= n; i++)//��2��ʼ�𲽲���
	{
		ps1.clear();
		for (it = ps.begin(); it != ps.end(); ++it)
		{
			insert(i, *it, ps1);
		}
		ps = ps1;
	}
}