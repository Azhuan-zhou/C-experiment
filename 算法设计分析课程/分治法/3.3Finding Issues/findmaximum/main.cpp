#include"head.h"
int main()
{
	int n = 10;
	int a[] = { 2,5,1,7,10,6,9,4,3,8 };
	int max1=0,max2=0;
	find(a, 0, n - 1, max1, max2);
	cout << "���Ԫ��Ϊ��" << max1 << endl;
	cout << "�δ�Ԫ�أ�" << max2 << endl;
	return 0;
}