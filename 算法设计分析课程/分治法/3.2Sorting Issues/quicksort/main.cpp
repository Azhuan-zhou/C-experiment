#include "��ͷ.h"
int main()
{
	int n = 10;
	int a[10] = { 2,5,2,7,10,6,9,4,3,8 };
    cout << "δ���������Ϊ��" << endl;
	print(a, n);
	Quicksort(a, 0, 9);
	cout << "����������Ϊ��" << endl;
	print(a, n);
	return 0;
}
