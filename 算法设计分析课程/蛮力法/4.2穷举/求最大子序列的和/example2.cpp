#include<iostream>
using namespace std;
int main()
{
	int a[] = { -6 ,2,4,-7,5,3,2,-1,6,-9,10,-2 };
	int size = sizeof(a) / sizeof(int);
	int i, sum = 0, maxsum = 0;
	for (i = 0; i < size; i++)
	{
		sum += a[i];
		if (sum < 0)
		{
			sum = 0;
		}
		if (sum > maxsum)
		{
			maxsum = sum;
		}
	}
	cout << "最大连续子序列和为：" << maxsum << endl;
}