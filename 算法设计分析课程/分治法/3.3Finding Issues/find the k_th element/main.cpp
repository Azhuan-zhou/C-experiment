#include"head.h"
int main()
{
	int a[] = { 2,5,2,7,10,6,9,2,3,8 };
	int n = 10;
	int k, i;
	for (i = 0; i < n; i++)
	{
		k = quicksort(a, 0, n-1, i);
		cout << "第" << i+1  << "小的元素为：" << k<<endl;
	}
	return 0;
}