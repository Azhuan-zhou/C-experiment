#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct nodetype
{
	int no;//结点编号
	int row;//皇后所在行数
	vector<int> colums;//皇后所在列数,用一个数组保存
	bool operator<(const nodetype& e)const
	{
		return row < e.row;
	}
};
int n = 4;
int Count = 1;
void dispnode(nodetype e)
{
	if (e.row == -1)
	{
		cout << "编号：" << e.no << ",对应位置（" << e.row << ",*)" << endl;
	}
	else
	{
		cout << "编号：" << e.no << ",对应位置（" << e.row << "," << e.colums[e.row] << ")" << endl;
	}

}
void dispsolution(nodetype& e)
{
	cout << "产生一个解：";
	for (int i = 0; i < n; i++)
	{

		cout << "[" << i + 1 << "," << e.colums[i] + 1 << "] ";
	}
	cout << endl;
}
bool place(vector<int> colums, int i, int j)//判度第（i，j）位置是否可以放下皇后
{
	int k = 0;
	while (k < i)//从第1行向下试探
	{
		if ((colums[k] == j) || (abs(i - k)) == (abs(j - colums[k])))
		{
			return false;
		}
		k++;
	}
	return true;
}
void solve()
{
	priority_queue<nodetype> que;
	nodetype e, e1;
	int i, j;//行数
	//为起始结点赋初值
	e.no = Count++;
	e.row = -1;
	que.push(e);
	cout << "进队：";
	dispnode(e);
	while (!que.empty())
	{
		e = que.top();
		que.pop();
		cout << "    出队：";
		dispnode(e);
		if (e.row == n - 1)//如果走到叶子结点，输出这个解
		{
			dispsolution(e);
			return;//只产生一个解
		}
		else//拓展这个根节点
		{
			for (j = 0; j < n; j++)
			{
				i = e.row + 1;//行数
				if (place(e.colums, i, j))//只有当（i,j）可以放下皇后时，才可以将结点放入队列
				{
					//为子节点赋值
					e1.no = Count++;
					e1.row = i;
					e1.colums = e.colums;
					e1.colums.push_back(j);
					que.push(e1);
					cout << "进队：";
					dispnode(e1);
				}
			}
		}
	}
}
int main()
{
	cout << n << "皇后问题的求解过程：" << endl;
	solve();

}