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
void comb(int n, int k)//k是数字在数组位置，n是要放入该位置的数字
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
			comb(i - 1,k- 1);//从高位向低位递归
		}
	}
}
int main()
{
	int n = 5;
	int k = 3;
	cout << "1~" << n << "中" << k << "个整数得所有组合为："<<endl;
	comb(n, k);
}