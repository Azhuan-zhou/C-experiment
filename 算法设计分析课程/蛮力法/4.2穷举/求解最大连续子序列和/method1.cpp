#include<iostream>
using namespace std;
int main()
{
	int a[] = { -6 ,2,4,-7,5,3,2,-1,6,-9,10,-2 };
	int size = sizeof(a) / sizeof(int);
	int i, j,sum=0,maxsum=0;
	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
		{
			sum += a[j];
			if (sum > maxsum)
			{
				maxsum = sum;
			}
		}
		sum = 0;
	}
	cout << "������������к�Ϊ��" << maxsum << endl;
}