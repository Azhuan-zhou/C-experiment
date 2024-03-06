#include<iostream>
#include<algorithm>
#define MAX 20
using namespace std;
struct animal
{
	int no;//牛的编号
	int start;//起始时间
	int end;//结束时间
	bool operator<(const animal& A) const
	{
		if (end == A.end)
		{
			return start <= A.start;
		}
		else
		{
			return end <= A.end;
		}
	}
};
int n = 5;//牛的个数
animal A[] = { {0},{1,1,10},{2,2,4},{3,3,6},{4,5,8},{5,4,7} };//活动时间，
int Fence[MAX] = { 0 };//Fence[i]=num,表示第i个动物放在第num个蓄栏
int num = 1;//蓄栏编号
void solve()
{
	int i;
	int end = 0;//用于储存上一个挤奶的结束时间
	sort(A, A + n + 1);//根据结束时间递增排序
	for (i = 1; i <= n; i++)
	{
		if (Fence[i] == 0)
		{
			Fence[i] = ::num;
			end = A[i].end;
			for (int j = i+1; j <= n; j++)
			{
				if (Fence[j] == 0 && A[j].start>end)
				{
					Fence[j] = ::num;
					end = A[j].end;
				}
			}
			::num++;
		}
	}
}
void disp()
{
	int i;
	cout << "求解结果" << endl;
	for (i = 1; i <= n; i++)
	{
		cout << "牛" << A[i].no << "安排的蓄栏：" << Fence[i]<<endl;
	}
}
int main()
{
	solve();
	disp();
}