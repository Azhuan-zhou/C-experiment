#include"head.h"
int main()
{
	int minicost = 100000;
	int minip = 0;//最小成本方案
	int n = 4,i=1;
	vector<int>::iterator it;
	vector<vector<int>> ps;
	allocate(n, minicost, minip,ps);
	cout << "任务安排：" << endl;
	for (it = ps[minip].begin(); it != ps[minip].end(); ++it)
	{
		cout << "第" << i << "份任务由人员" << *it << "完成" << endl;
		i++;
	}
	cout << "总成本=" << minicost;
}