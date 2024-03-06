#include"head.h"
int main()
{
	int n = 10;
	int a[] = { 0,1,2,3,4,5,6,7,8,9 };
	int k,i;
	cout << "请输入你要查找的数字：";
	cin >> k;
	i=binsearch(a, 0, n - 1, k);
	if (i >= 0)
	{
		cout << "a[" << i << "]=" << k << endl;
	}
	else
	{
		cout << "该数字不在数组中" << endl;
	}
	

}