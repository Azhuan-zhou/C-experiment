#include<iostream>
#define N 20
using namespace std;
int a[N][N];//�ڽӾ���
int x[N];//��ɫ����
int n;//������
int k;//�ߵĸ���
int m;//��ɫ����ɫ
int t=0;//������
void disp()//��������Ľ�
{
	int i;
	cout << "��" << t << "����ɫ����Ϊ��";
	for (i = 1; i <= n ; i++)
	{
		cout << x[i] ;
	}
	cout << endl;

}
bool same(int i)//��֦������������ʱ��֦
{
	for (int j = 1; j <= n; j++)
	{
		if (a[i][j] == 1 && x[i] == x[j])//���i�ͽ��j�б�������������ɫ��ͬʱ������false����֦
		{
			return false;
		}
	}
	return true;//���򷵻�true
}
void fun(int i)
{
	if (i > n)//��������������һ��
	{
		t++;
		disp();
	}
	else
	{
		for (int j = 1; j <= m; j++)
		{
			x[i] = j;//�����i�ŵ�jɫ
			if (same(i))//��������ʱ��չ���
			{
				fun(i + 1);
			}
			x[i] = 0;//����
		}
	}

}
int main()
{
	int x, y;//���
	cin >> n >> k >> m;//�������������,�ߵĸ���,��ɫ�ĸ���
	for (int i = 1; i <= k; i++)//����
	{
		cin >> x >> y;//����������ӵĽ��
		a[x][y] = 1;
		a[y][x] = 1;
	}
	fun(1);
}