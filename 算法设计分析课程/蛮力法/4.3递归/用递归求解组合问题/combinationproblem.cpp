#include<iostream>
#include<iomanip>
#define MAXK 3
using namespace std;
int a[MAXK];
void disp()
{
	int i;
	for (i = 0; i < sizeof(a)/sizeof(int) ; i++)
	{
		cout << setw(5) << a[i];
	}
	cout << endl;
}
void comb(int n, int k)//k������������λ�ã�n��Ҫ�����λ�õ�����
{
	int i;
	if (k==0)
	{
		disp();
	}
	else
	{
		for (i = k; i <= n; i++)
		{
			a[k - 1] = i;
			comb(i - 1,k- 1);//�Ӹ�λ���λ�ݹ�
		}
	}
}
int main()
{
	int n = 5;
	int k = 3;
	cout << "1~" << n << "��" << k << "���������������Ϊ��"<<endl;
	comb(n, k);
}