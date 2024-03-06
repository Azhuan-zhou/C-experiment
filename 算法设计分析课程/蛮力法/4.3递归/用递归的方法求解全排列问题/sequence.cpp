#include<iostream>
#include<vector>
using namespace std;
void perm(int i, int n, vector<vector<int>> &ps);
void inserti(vector<int>& s, vector<vector<int>>& ps1, int i);
int main()
{
	vector<vector<int>> ps;//存放全排列的向量
	vector<vector<int>>::iterator it1;
	vector<int>::iterator it2;
	vector<int> s;
	int n = 3;
	s.push_back(1);
	ps.push_back(s);
	perm(2, n, ps);
	for (it1 = ps.begin(); it1 != ps.end(); ++it1)//输出
	{
		cout << " { ";
		for (it2 = (*it1).begin(); it2 != (*it1).end(); ++it2)
		{
			cout << " " << *it2 << " ";
		}
		cout << " } " << endl;
	}
}
void perm(int i, int n, vector<vector<int>> &ps)//构造全排列
{
	vector<vector<int>>::iterator it;
	if (i <= n)
	{
		vector<vector<int>> ps1;
		for (it = ps.begin(); it != ps.end(); ++it)
		{
			inserti(*it, ps1, i);
		}
		ps = ps1;
		perm(i + 1, n, ps);
	}
}
void inserti(vector<int> &s, vector<vector<int>> &ps1, int i)//插入数字
{
	vector<int> s1;
	vector<int>::iterator it;
	int j;
	for (j=0;j<i;j++)
	{
		s1 = s;
		it = s1.begin() + j;
		s1.insert(it, i);
		ps1.push_back(s1);
	}

}