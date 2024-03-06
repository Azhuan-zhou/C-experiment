#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define N 20
using namespace std;
struct Activity
{
	int b;//起始时间
	int e;//结束时间
	int length;//活动的时间长度
	bool operator <(const Activity& A)const
	{
		return e < A.e;//活动按照结束时间递增排序
	}
};
int n = 11;
Activity A[N] = { {1,4},{3,5},{0,6},{5,7},{3,8},{5,9},{6,10},{8,11},{8,12},{2,13},{12,15} };
int dp[N];
int pre[N];
void solve()
{
	memset(dp, 0, sizeof(dp));
	sort(A, A + n);
	dp[0] = 0;
	pre[0] = -1;
	for (int i = 1; i < n; i++)
	{
		int low = 0;
		int high = i - 1;
		while (low <= high)//二分查找，查找举办结束的时间最接近活动i举办的时间
		{
			int mid = (high + low) / 2;
			if (A[mid].e <= A[i].b)//活动i举办前可以举办活动mid，则在mid后的序列继续查找
			{
				low = mid + 1;
			}
			else // 活动i举办前不可以举办活动mid，则在mid前的序列继续查找
			{
				high = mid-1;
			}
		}
		if (low == 0)
		{
			if (dp[i - 1] >= A[i].length)//不选择第i个活动
			{
				dp[i] = dp[i - 1];
				pre[i] = -2;
			}
			else
			{
				dp[i] = A[i].length;
				pre[i] = -1;//没有前驱订单
			}
		}
		else
		{
			if (dp[i - 1] >= dp[low - 1] + A[i].length)//不选择订单
			{
				dp[i] = dp[i - 1];
				pre[i] = -2;
			}
			else
			{
				dp[i] = dp[low-1]+A[i].length;
				pre[i] = low-1;//没有前驱订单
			}
		}
	}
}
void disp()
{
	vector<int> res;
	int i = n - 1;
	while (true)
	{
		if (i == -1)
		{
			break;
		}
		if (pre[i] == -2)
		{
			i--;
		}
		else
		{
			res.push_back(i);
			i = pre[i];
		}
	}
	vector<int>::reverse_iterator it;
	cout << "选择的订单为：" << endl;
	for (it = res.rbegin(); it != res.rend(); it++)
	{
		printf("%d[%d,%d]", *it, A[*it].b, A[*it].e);
	}
	cout << endl;
	cout << "兼容订单的总时间为：" << dp[n - 1] << endl;
}
int main()
{
	int i;
	for(i=0;i<n;i++)
	{ 
		A[i].length = A[i].e - A[i].b;
	}
	solve();
	disp();
}