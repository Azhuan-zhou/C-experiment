#include"head.h"
void inserti(vector<vector<int>> &ps, int i)
{
	vector<vector<int>> ps1;
	vector<vector<int >>::iterator it;
	ps1 = ps;
	for (it = ps1.begin(); it != ps1.end(); ++it)//��ԭ���ļ��ϲ�������i
	{
		(*it).push_back(i);
	}
	for (it = ps1.begin(); it != ps1.end(); ++it)//���¼�����ԭ���Ϻϲ�
	{
		ps.push_back(*it);
	}

}
