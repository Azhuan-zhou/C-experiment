#include<iostream>
using namespace std;
struct activity
{
	int start;
	int end;
};
const activity a[5] = { {1,3},{4,8},{6,10},{2,5},{3,5} };//�����ʼʱ��ͽ���ʱ��
int x[5] = { 1,2,3,4,5 };//��ռ�����
int X[5];//��žٰ����Ľ�ռ�����
const int n = 5;//�����
int maxcount = 0;//�ٰ�����ĸ���
void swap(int &a, int &b)//����
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void disp()//���
{
	cout << "���ŵ��ȷ�����" << endl;
	int last = 0;
	for (int j = 0; j < n; j++)
	{
		if (a[X[j] - 1].start >= last)//������ѵĽ���������ٰܾ�Ļ
		{
			last = a[X[j] - 1].end;
			cout << "ѡȡ�" << X[j] << ": [" << a[X[j] - 1].start << "," << a[X[j] - 1].end << ")" << endl;
			
		}
	}
	cout << "���Ż������" << maxcount << "��";
}
void fun(int i)
{
	if (i >= n)
	{
		int last = 0;
		int count = 0;
		for (int j = 0; j < n; j++)//����ÿһ�������ٰ��ĸ���
		{
			if (a[x[j]-1].start >= last)
			{
				count++;
				last = a[x[j]-1].end;
			}
		}
		if (count > maxcount)//�ҳ��ٰܾ���෽��
		{
			maxcount = count;
			for (int j = 0; j < n; j++)
			{
				X[j] = x[j];
			}
		}
	}
	else
	{
		for (int j = i; j < n; j++)
		{
			swap(x[i], x[j]);//����
			fun(i + 1);
			swap(x[i], x[j]);//����

		}
	}
}
int main()
{
	fun(0);
	disp();
}