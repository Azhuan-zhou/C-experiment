#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n = 3;//加工机器个数
int m = 7;//加工工件个数
struct machine
{
	int no;//工件编号
	int time;//执行时间
	int mno;//机器序号
	bool operator<(const machine& a)const
	{
		return time > a.time;//执行时间少得优先出队列,排序中时间大得排在前面
	}
};
machine A[] = { {1,2},{2,14},{3,4},{4,16},{5,6},{6,5},{7,3} };
void solve()
{
	if (n >= m)
	{
		cout << "直接在机器上加工" << endl;
	}
	else
	{
		int i;
		machine e;
		priority_queue<machine> que;
		sort(A, A + m);
		for (i = 0; i < n; i++)
		{
			A[i].mno = i + 1;
			que.push(A[i]);
			cout << "给机器" << A[i].mno << "分配作业" << A[i].no << ",占用时间段:[0," << A[i].time << "]" << endl;
		}
		for (i = n; i < m; i++)
		{
			e = que.top();
			que.pop();
			cout << "给机器" << e.mno << "分配作业" << A[i].no << ",占用时间段:[," << e.time << "," << e.time + A[i].time << "]" << endl;
			e.time += A[i].time;
			que.push(e);
		}
	}
}
int main()
{
	cout << "多机调度问题" << endl;
	solve();
}