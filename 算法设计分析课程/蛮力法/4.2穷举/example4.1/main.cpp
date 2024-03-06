#include<iostream>
using namespace std;
int main()
{
	int num=0, t;
	int i, j;
	for (i = 2; i < 1000; i++)
	{
		for (j = 1; j < i; j++)
		{
			if (i % j == 0)
			{
				num += j;
			}
		}
		if (num == i)
		{
			cout << num << " ";
		}
		num = 0;
	}
}