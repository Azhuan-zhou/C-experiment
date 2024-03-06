#include"head.h"
void knap(int w[],int v[],int W, vector<vector<int>>& ps)
{
	int sumw=0, sumv=0;
	int maxsumv=0,maxsumw=0;
	int maxp=0;
	int count = 0;
	vector<vector<int>>::iterator it1;//指向方案的迭代器
	vector<int>::iterator it2;//指向物品的迭代器
	cout << setw(12) << "序号" << setw(12) << "选中物品" << setw(12) << "总重量" << setw(12) << "总价值" << setw(12) << "能否装入"<<endl;
	for (it1 = ps.begin(); it1 != ps.end(); ++it1)
	{
		cout << setw(12) << count+1;//打印出方案序号
		cout << "{";
		for (it2 = (*it1).begin(); it2 != (*it1).end(); ++it2)//方案
		{
			cout << *it2 << " ";//打印出选择的物品
			sumw += w[*it2 - 1];//计算该方案下的重量总和
			sumv += v[*it2 - 1];//计算该方案下的价值总和
		}
		cout << "}";
		cout << setw(12) << sumw << setw(12) << sumv;//打印方案下的重量总和和价值总和
		if (sumw <= W)//判断总重量是否满足条件
		{
			cout << setw(12) << "能";
			if (maxsumv > sumv)//找出符合条件方案中最大价值的方案
			{
				maxsumv = sumv;
				maxsumw = sumw;
				maxp = count;//最大价值方案的序号
			}
		}
		else
		{
			cout<<setw(12) << "否";
		}
		cout << endl;
		count++;
	}
	cout << "最佳方案为：选中物品";
	cout << "{";
	for (it2 = ps[maxp].begin(); it2 != ps[maxp].end(); ++it2)
	{
		cout << *it2 << " ";
	}
	cout << "}," << "总重量：" << maxsumw << "总价值：" << maxsumv;
}