#include"head.h"
int main()
{
	int a[] = { 11,13,15,17,19 };
	int b[] = { 2,4,6,8,20 };
	int k = midnum(a, 0, 4, b, 0, 4);
	cout << "两个有序数组的中位数为：" << k << endl;
}