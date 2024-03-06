#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n = 3;//�ӹ���������
int m = 7;//�ӹ���������
struct machine
{
	int no;//�������
	int time;//ִ��ʱ��
	int mno;//�������
	bool operator<(const machine& a)const
	{
		return time > a.time;//ִ��ʱ���ٵ����ȳ�����,������ʱ��������ǰ��
	}
};
machine A[] = { {1,2},{2,14},{3,4},{4,16},{5,6},{6,5},{7,3} };
void solve()
{
	if (n >= m)
	{
		cout << "ֱ���ڻ����ϼӹ�" << endl;
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
			cout << "������" << A[i].mno << "������ҵ" << A[i].no << ",ռ��ʱ���:[0," << A[i].time << "]" << endl;
		}
		for (i = n; i < m; i++)
		{
			e = que.top();
			que.pop();
			cout << "������" << e.mno << "������ҵ" << A[i].no << ",ռ��ʱ���:[," << e.time << "," << e.time + A[i].time << "]" << endl;
			e.time += A[i].time;
			que.push(e);
		}
	}
}
int main()
{
	cout << "�����������" << endl;
	solve();
}