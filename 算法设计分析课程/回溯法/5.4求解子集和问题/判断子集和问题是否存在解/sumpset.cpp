#include<iostream>
#define N 4
using namespace std;
int w[] = { 11,13,24,7 };
void fun(int i, int tw, int rw,int W,int &count)
{
	if (i == N)//���������е�Ԫ��
	{
		if (tw == W)//�������ܺ͵���Ҫ����Ӽ���ʱ
		{
			count++;//��ĸ�����һ
		}
	}
	else
	{
		//��֦��ѡ���i����
		if (tw + w[i] <= W)
		{
			fun(i + 1, tw + w[i], rw - w[i],W,count);
		}
		//��֦����ѡ���i����
		if (tw + rw - w[i] >= W)
		{
			fun(i + 1, tw, rw - w[i],W,count);
		}
	}
}
int sum(int a[])//���
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += a[i];
	}
	return sum;
}
bool solve(int W)//�жϵ��Ӽ���ΪWʱ�Ƿ���ڽ�
{
	int Sum=sum(w);
	int count = 0;
	fun(0, 0, Sum, W, count);
	if (count > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int W;
	W = 7;
	//W = 7
	cout << "W=" << W << "ʱ��";
	if (solve(W))
	{
		cout << "���ڽ�"<<endl;
	}
	else
	{
		cout << "û�н�"<<endl;
	}
	W = 15;
	//W = 15
	cout << "W=" << W << "ʱ��";
	if (solve(W))
	{
		cout << "���ڽ�" << endl;
	}
	else
	{
		cout << "û�н�" << endl;
	}
	W = 21;
	//W=21
	cout << "W=" << W << "ʱ��";
	if (solve(W))
	{
		cout << "���ڽ�" << endl;
	}
	else
	{
		cout << "û�н�" << endl;
	}
	W = 24;
	//W = 24
	cout << "W=" << W << "ʱ��";
	if (solve(W))
	{
		cout << "���ڽ�" << endl;
	}
	else
	{
		cout << "û�н�" << endl;
	}
}