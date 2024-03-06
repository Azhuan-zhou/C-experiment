#include<iostream>
#include<queue>
using namespace std;
struct nodetype
{
	int no;
	bool operator<(const nodetype& e)const
	{
		return no < e.no;
	}
};
nodetype A[] = { {1},{2},{5},{6}, {9} };
int n = 5;
int main()
{
	nodetype e;
	priority_queue<nodetype> que;
	for (int i = 0; i < 5; i++)
	{
		que.push(A[i]);
	}
	for (int i = 0; i < 5; i++)
	{
		e = que.top();
		que.pop();
		cout << e.no;
	}
}