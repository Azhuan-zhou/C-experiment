#include"head.h"
int main()
{
	int n = 10;
	int a[] = { 0,1,2,3,4,5,6,7,8,9 };
	int k,i;
	cout << "��������Ҫ���ҵ����֣�";
	cin >> k;
	i=binsearch(a, 0, n - 1, k);
	if (i >= 0)
	{
		cout << "a[" << i << "]=" << k << endl;
	}
	else
	{
		cout << "�����ֲ���������" << endl;
	}
	

}