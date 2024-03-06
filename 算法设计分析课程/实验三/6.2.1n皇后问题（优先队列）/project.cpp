#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct nodetype
{
	int no;//�����
	int row;//�ʺ���������
	vector<int> colums;//�ʺ���������,��һ�����鱣��
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
		cout << "��ţ�" << e.no << ",��Ӧλ�ã�" << e.row << ",*)" << endl;
	}
	else
	{
		cout << "��ţ�" << e.no << ",��Ӧλ�ã�" << e.row << "," << e.colums[e.row] << ")" << endl;
	}

}
void dispsolution(nodetype& e)
{
	cout << "����һ���⣺";
	for (int i = 0; i < n; i++)
	{

		cout << "[" << i + 1 << "," << e.colums[i] + 1 << "] ";
	}
	cout << endl;
}
bool place(vector<int> colums, int i, int j)//�жȵڣ�i��j��λ���Ƿ���Է��»ʺ�
{
	int k = 0;
	while (k < i)//�ӵ�1��������̽
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
	int i, j;//����
	//Ϊ��ʼ��㸳��ֵ
	e.no = Count++;
	e.row = -1;
	que.push(e);
	cout << "���ӣ�";
	dispnode(e);
	while (!que.empty())
	{
		e = que.top();
		que.pop();
		cout << "    ���ӣ�";
		dispnode(e);
		if (e.row == n - 1)//����ߵ�Ҷ�ӽ�㣬��������
		{
			dispsolution(e);
			return;//ֻ����һ����
		}
		else//��չ������ڵ�
		{
			for (j = 0; j < n; j++)
			{
				i = e.row + 1;//����
				if (place(e.colums, i, j))//ֻ�е���i,j�����Է��»ʺ�ʱ���ſ��Խ����������
				{
					//Ϊ�ӽڵ㸳ֵ
					e1.no = Count++;
					e1.row = i;
					e1.colums = e.colums;
					e1.colums.push_back(j);
					que.push(e1);
					cout << "���ӣ�";
					dispnode(e1);
				}
			}
		}
	}
}
int main()
{
	cout << n << "�ʺ�����������̣�" << endl;
	solve();

}