#include "标头.h"
int main()
{
	int n = 10;
	int a[10] = { 2,5,2,7,10,6,9,4,3,8 };
    cout << "未排序的数组为：" << endl;
	print(a, n);
	Quicksort(a, 0, 9);
	cout << "排序后的数组为：" << endl;
	print(a, n);
	return 0;
}
