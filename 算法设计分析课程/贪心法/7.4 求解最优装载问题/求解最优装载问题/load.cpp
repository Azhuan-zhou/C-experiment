#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int n = 5;//五个货箱
int w[] = { 0,5,2,6,4,3 };//货箱重量
int W = 10;//轮船上限重量
int maxw;
int x[5];
void solve()
{
	sort(w + 1, w + n + 1);
	maxw = 0;
	for (int i = 1; i <= n; i++)
	{
		maxw += w[i];
		x[i] = 1;
		if (maxw > W)
		{
			maxw = maxw - w[i];
			x[i] = 0;
			break;
		}

	}
}
void disp()
{
	for (int i = 0; i <= n; i++)
	{
		if (x[i] == 1)
		{
			cout <<setw(2)<< "选取重量为" << w[i] << "的集中箱" << endl;
		}
	}
	cout << "总重量:" << maxw;
}
int main()
{
	solve();
	disp();
}