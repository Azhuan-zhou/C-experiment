#include<iostream>
#include<queue>
#include<map>
#include<string>
#include<vector>
#define N 100
using namespace std;
int n;//������
struct HTreeNode
{
	char symbol;//�������
	int weight;//���Ȩֵ
	int parent;//���׽��
	int lchild;//���ӽ��
	int rchild;//�Һ��ӽ��
};
HTreeNode Tree[N];
struct Nodetype//���ã������µĹ��������Ľ��
{
	int no;//����ţ���һ��ʼ
	int weight;
	char symbol;
	bool operator<(const Nodetype& e)const
	{
		return weight > e.weight;//С����
	}
};
map<char, string> Hcode;//�����Ź������������ĸ
void CreateHTree()
{
	Nodetype e, e1, e2;//e��������ΪҶ�ӽ�㸳ֵ���������ȶ����кͽ������ɵĽ��������ȶ����У�e1��e2�������ǽ����ȶ��е���С����������ó������ɸ��׽��
	priority_queue<Nodetype> que;//���ڴ�������ɵĹ����������
	for (int k = 1; k <= 2 * n - 1; k++)
	{
		Tree[k].parent = Tree[k].rchild = Tree[k].lchild = -1;//��ʼ�����еĹ��������Ľڵ�
	}
	for (int j = 1; j <= n; j++)//��Ҷ�ӽ��������ȶ�����
	{
		e.no = j;
		e.symbol = Tree[j].symbol;
		e.weight = Tree[j].weight;
		que.push(e);
	}
	for (int i = n+1; i <= 2*n -1; i++)//һ�����������������n���ӽڵ㣬����n-1��Ҷ�ӽ��
	{
		e1 = que.top();
		que.pop();
		e2 = que.top();
		que.pop();
		//Ϊ���ӽ�㸳ֵ
		Tree[i].weight = e1.weight + e2.weight;
		cout << Tree[i].weight << endl;
		Tree[i].lchild = e1.no;
		Tree[i].rchild = e2.no;
		Tree[i].symbol = ' ';
		//Ϊ���ӽ�㸳ֵ���׽��ı��
		Tree[e1.no].parent = i;
		Tree[e2.no].parent = i;
		//�����ӽ��������ȶ�����
		e.no = i;
		e.weight = e1.weight + e2.weight;
		que.push(e);
	}
}
void CreateHCode()
{
	int i;
	string code;
	for (i = 1; i <= n; i++)//��������Ҫ�����Ҷ�ӽ��
	{
		code = " ";
		code.reserve(N);
		int curno = i;//��ǰ������
		int Parent = Tree[curno].parent;//��ǰ���ĸ��׽�����
		while (Parent != -1)
		{
			if (Tree[Parent].lchild == curno)
			{
				code = '0'+code;//���Ҷ�ӽ��curno����parent������ڵ㣬����1
			}
			else 
				code = '1'+code;//���Ҷ�ӽ��curno����parent�����ҽڵ㣬����0
			curno = Parent;
			Parent = Tree[curno].parent;
		}
		Hcode[Tree[i].symbol] = code;//����i��Ҷ�ӽ�����ĸ�ͱ��һһ��Ӧ
	}
}
void dispHCode()//�������������
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
	cout << "����Ĺ���������" << endl;
	dispHTree();
	CreateHCode();
	cout << "�����Ĺ���������Ϊ��" << endl;
	dispHCode();
	cout << "WPL=" << WPL() << endl;

}