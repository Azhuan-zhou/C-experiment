#include<iostream>
#define N 10
using namespace std;
bool used[N + 1];//used[i]=true 表示第i个数字可以使用
int a[9];//存放3x3个方格
int count=0;
int checkmatric[][3] = { {-1},{0,-1},{1,-1},{0,-1},{1,3,-1},{2,4,-1},{3,-1},{4,6,-1},{5,7,-1} };//checkmatrix[1][3]表示第二个位置向前相邻的数字的位置
void disp(int a[])//输出解
{
	int i, j;
	cout << "解" << ++::count<<endl;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cout << a[3 * i + j]<<" ";
		}
		cout << endl;
	}
}
bool isPrime(int m)//判断m是否为素数
{
	bool flag = true;
	for (int i = 2; i < m; i++)
	{
		if (m % i == 0)
		{
			return false;
		}
	}
	return true;
}
bool check(int pos)//检查a中pos位置的相邻两个方格内的数字之和是否为素数
{
	int i;
	int j;//记录pos前相邻的位置
	if (pos < 0)
		return false;
	for (i = 0; (j = checkmatric[pos][i] )>= 0; i++)
	{
		if (!isPrime(a[pos] + a[j]))
		{
			return false;//相邻位置之和有一个不是素数返回false
		}
	}
	return true;
}
int selectnum(int start)//从start开始选择一个没有使用过的数字
{
	for (int j = start; j <= N; j++)
	{
		if (used[j])
		{
			return j;
		}
	}
	return 0;
}
int extend(int pos)//为pos位置选择一个没有使用过的数字
{
	a[++pos] = selectnum(0);
	used[a[pos]] = false;
	return pos;
}
int change(int pos)//回溯
{
	int j;
	//为pos位置重新选择一个数字，如果pos大于0并且无法给pos在选择一个值时，将pos上一个位置也重新选择一个值
	while (pos >= 0 && (j = selectnum(a[pos] + 1)) == 0)
	{
		used[a[pos--]] = true;
	}
	if (pos < 0)
		return-1;
	used[a[pos]] = true;
	a[pos] = j;
	used[j] = false;
	return pos;
}
void solve()
{
	bool ok = true;
	int pos = 0;
	a[pos] =1;
	used[a[pos]] = false;
	while (pos >= 0)
	{
		if (ok)
		{
			if (pos == 8)
			{
				disp(a);
				pos = change(pos);
			}
			else
			{
				pos = extend(pos);
			}
		}
		else
		{
			pos = change(pos);
		}
		ok = check(pos);
	}
}
int main()
{
	for (int i = 1; i <= N; i++)
	{
		used[i] = true;
	}
	solve();
	cout << "count=" << ::count << endl;
}