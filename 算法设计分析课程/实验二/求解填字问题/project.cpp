#include<iostream>
#define N 10
using namespace std;
bool used[N + 1];//used[i]=true ��ʾ��i�����ֿ���ʹ��
int a[9];//���3x3������
int count=0;
int checkmatric[][3] = { {-1},{0,-1},{1,-1},{0,-1},{1,3,-1},{2,4,-1},{3,-1},{4,6,-1},{5,7,-1} };//checkmatrix[1][3]��ʾ�ڶ���λ����ǰ���ڵ����ֵ�λ��
void disp(int a[])//�����
{
	int i, j;
	cout << "��" << ++::count<<endl;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cout << a[3 * i + j]<<" ";
		}
		cout << endl;
	}
}
bool isPrime(int m)//�ж�m�Ƿ�Ϊ����
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
bool check(int pos)//���a��posλ�õ��������������ڵ�����֮���Ƿ�Ϊ����
{
	int i;
	int j;//��¼posǰ���ڵ�λ��
	if (pos < 0)
		return false;
	for (i = 0; (j = checkmatric[pos][i] )>= 0; i++)
	{
		if (!isPrime(a[pos] + a[j]))
		{
			return false;//����λ��֮����һ��������������false
		}
	}
	return true;
}
int selectnum(int start)//��start��ʼѡ��һ��û��ʹ�ù�������
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
int extend(int pos)//Ϊposλ��ѡ��һ��û��ʹ�ù�������
{
	a[++pos] = selectnum(0);
	used[a[pos]] = false;
	return pos;
}
int change(int pos)//����
{
	int j;
	//Ϊposλ������ѡ��һ�����֣����pos����0�����޷���pos��ѡ��һ��ֵʱ����pos��һ��λ��Ҳ����ѡ��һ��ֵ
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