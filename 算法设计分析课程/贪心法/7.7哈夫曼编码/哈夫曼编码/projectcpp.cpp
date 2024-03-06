#include<iostream>
#include<queue>
#include<map>
#include<string>
#include<vector>
#define N 100
using namespace std;
int n;//结点个数
struct HTreeNode
{
	char symbol;//编码符号
	int weight;//结点权值
	int parent;//父亲结点
	int lchild;//左孩子结点
	int rchild;//右孩子结点
};
HTreeNode Tree[N];
struct Nodetype//作用：生成新的哈夫曼树的结点
{
	int no;//结点编号，从一开始
	int weight;
	char symbol;
	bool operator<(const Nodetype& e)const
	{
		return weight > e.weight;//小根堆
	}
};
map<char, string> Hcode;//用与存放哈夫曼编码和字母
void CreateHTree()
{
	Nodetype e, e1, e2;//e的作用是为叶子结点赋值并放入优先队列中和将新生成的结点放入优先队列中，e1和e2的作用是将优先队列的最小的两个结点拿出来生成父亲结点
	priority_queue<Nodetype> que;//用于存放新生成的哈夫曼数结点
	for (int k = 1; k <= 2 * n - 1; k++)
	{
		Tree[k].parent = Tree[k].rchild = Tree[k].lchild = -1;//初始化所有的哈夫曼树的节点
	}
	for (int j = 1; j <= n; j++)//将叶子结点放入优先队列中
	{
		e.no = j;
		e.symbol = Tree[j].symbol;
		e.weight = Tree[j].weight;
		que.push(e);
	}
	for (int i = n+1; i <= 2*n -1; i++)//一个哈夫曼数，如果有n个子节点，则有n-1个叶子结点
	{
		e1 = que.top();
		que.pop();
		e2 = que.top();
		que.pop();
		//为父子结点赋值
		Tree[i].weight = e1.weight + e2.weight;
		cout << Tree[i].weight << endl;
		Tree[i].lchild = e1.no;
		Tree[i].rchild = e2.no;
		Tree[i].symbol = ' ';
		//为孩子结点赋值父亲结点的编号
		Tree[e1.no].parent = i;
		Tree[e2.no].parent = i;
		//将父子结点放入优先队列中
		e.no = i;
		e.weight = e1.weight + e2.weight;
		que.push(e);
	}
}
void CreateHCode()
{
	int i;
	string code;
	for (i = 1; i <= n; i++)//对所有需要编码的叶子结点
	{
		code = " ";
		code.reserve(N);
		int curno = i;//当前结点序号
		int Parent = Tree[curno].parent;//当前结点的父亲结点序号
		while (Parent != -1)
		{
			if (Tree[Parent].lchild == curno)
			{
				code = '0'+code;//如果叶子结点curno是其parent结点的左节点，则编号1
			}
			else 
				code = '1'+code;//如果叶子结点curno是其parent结点的右节点，则编号0
			curno = Parent;
			Parent = Tree[curno].parent;
		}
		Hcode[Tree[i].symbol] = code;//将第i个叶子结点的字母和编号一一对应
	}
}
void dispHCode()//输出哈夫曼编码
{
	map<char, string>::iterator it;
	for (it = Hcode.begin(); it != Hcode.end(); it++)
	{
		cout << " " << it->first << ":" << it->second << endl;
	}
}
void dispHTree()
{
	for (int i = 1; i <= 2 * n - 1; i++)
	{
		cout << "symbol=" << Tree[i].symbol << "," << "weight=" << Tree[i].weight << "," << "lchild=" << Tree[i].lchild << "," << "rchild=" << Tree[i].rchild << "," << "parent=" << Tree[i].parent << endl;
	}
}
int WPL()
{
	int WPs = 0;
	for (int i = 1; i <= n; i++)
	{
		WPs += Tree[i].weight * (Hcode[Tree[i].symbol].size()-1);
	}
	return WPs;
}
int main()
{
	n = 5;
	Tree[1].symbol = 'a', Tree[1].weight = 4;
	Tree[2].symbol = 'b', Tree[2].weight = 2;
	Tree[3].symbol = 'c', Tree[3].weight = 1;
	Tree[4].symbol = 'd', Tree[4].weight = 7;
	Tree[5].symbol = 'e', Tree[5].weight = 3;
	CreateHTree();
	cout << "构造的哈夫曼树：" << endl;
	dispHTree();
	CreateHCode();
	cout << "产生的哈夫曼代码为：" << endl;
	dispHCode();
	cout << "WPL=" << WPL() << endl;

}