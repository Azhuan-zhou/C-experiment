#include"head.h"
int main()
{
	int a[] = { 2,5,1,7,10,6,9,4,3,8 };
	int n = 10;
	cout << "δ����ǰ������Ϊ��" << endl;
	print(a, n);
	mergesort(a, n);
	cout << "����������Ϊ��" << endl;
	print(a, n);
	return 0;
}