#include<iostream>
#define MAX 3
using namespace std;
const int a[] = {1,2,3};
const int n = MAX;
void disp(int x[])//���ݽ���������ݼ�Ԫ��
{
	int i;
	cout << " { ";
	for (i = 0; i < n; i++)
	{
		if (x[i] == 1)
		{
			cout << " " << a[i] << " ";
		}		
	}
	cout << " } "<<endl;
}
void pset(int i,int x[])
{
	if (i >= n)
	{
		disp(x);
	}
	else
	{
		x[i] = 0;//��֦��ѡ�������
		pset(i + 1, x);
		x[i] = 1;//��֦ѡ�������
		pset(i + 1, x);
	}
}
int main()
{
	int x[MAX] = { 0 };
	cout << "�������"<<endl;
	pset(0, x);
}
