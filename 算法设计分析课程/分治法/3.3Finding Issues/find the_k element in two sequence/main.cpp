#include"head.h"
int main()
{
	int a[] = {1,5,8};
	int b[] = {2,3,4,6,7};
	int k, element;
	int n = sizeof(a) / sizeof(int);
	int m = sizeof(b) / sizeof(int);
	for (k = 0; k < n + m;k++)
	{
		element = find(a, n, b, m, k + 1);
		cout << "������������ĵ�" << k + 1 << "��Ԫ��Ϊ��" << element << endl;
	}

}