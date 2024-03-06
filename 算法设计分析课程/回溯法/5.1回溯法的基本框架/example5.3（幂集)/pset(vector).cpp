#include<iostream>
#include<vector>
#define MAX 3
using namespace std;
const int a[] = { 1,2,3 };
const int n = MAX;
void disp(vector<int> ps)//输出动态数组
{
	cout << " { ";
	for (int i=0;i<ps.size();i++)
	{
		cout << " " << ps[i] << " ";
	}
	cout << " } ";
}
void pset(int i, const int a[], vector<int>& ps)//i为数的高度，a[]是储存幂集元素的数组，ps为动态数组
{
	if (i >= n)
	{
		disp(ps);
	}
	else
	{
		pset(i + 1, a, ps);//右枝
		ps.push_back(a[i]);
		pset(i + 1, a, ps);//左枝
	}
}
int main()
{
	vector<int> ps;
	cout << "1~3的幂集：" << endl;
	pset(0, a , ps);
}