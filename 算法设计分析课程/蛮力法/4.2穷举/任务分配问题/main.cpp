#include"head.h"
int main()
{
	int minicost = 100000;
	int minip = 0;//��С�ɱ�����
	int n = 4,i=1;
	vector<int>::iterator it;
	vector<vector<int>> ps;
	allocate(n, minicost, minip,ps);
	cout << "�����ţ�" << endl;
	for (it = ps[minip].begin(); it != ps[minip].end(); ++it)
	{
		cout << "��" << i << "����������Ա" << *it << "���" << endl;
		i++;
	}
	cout << "�ܳɱ�=" << minicost;
}