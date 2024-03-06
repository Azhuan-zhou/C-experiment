#include<iostream>
#include<algorithm>
#define MAX 20
using namespace std;
struct activity
{
	int start;//起始时间
	int end;//结束时间
	bool operator<(const activity&A) const
	{
		return end < A.end;
	}
};
int n = 11;//活动个数
activity A[] = { {0},{1,4},{3,5},{0,6},{5,7},{3,8},{5,9},{6,10},{8,11},{8,12},{2,13},{12,15} };//活动时间
bool flag[MAX] = { 0 };
int count=0;
void solve()
{
	int i;
	int end=0;//用于储存上一个活动的技术时间
	sort(A, A + n + 1);//根据结束时间递增排序
	for (i = 1; i <= n; i++)
	{
		if (A[i].start >= end)
		{
			flag[i] = true;
			end = A[i].end;
			::count++;
		}
	}
}
void disp()
{
	int i;
	cout << "求解结果" << endl;
	cout << "选取活动：";
	for (i = 1; i <= n; i++)
	{
		if (flag[i])
		{
			cout <<"活动"<<i<< "[" << A[i].start << "," << A[i].end << "] ";
		}
	}
	cout << endl;
	cout << "          一共有" << ::count << "个活动" << endl;
}
int main()
{
	solve();
	disp();
}