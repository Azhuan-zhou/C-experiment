#include<iostream>
using namespace std;
int main()
{
	int a[] = { 4,5,8,20 };
	int i, j, k;
	int x,y,z;
	int round, maxround=0;
	int size = sizeof(a) / sizeof(int);
	for (i = 0; i < size; i++)
	{
		for (j = i+1; j < size; j++)
		{
			for (k = j+1; k < size;k++)
			{
				x = a[i];
				y = a[j];
				z = a[k];
				if (x + y > z && x + z > y && z + y > x)
				{
					round = x + y + z;
					if (round > maxround)
					{
						maxround = round;
					}
				}
			}
		}
	}
	cout << "三角形的周长为：" << maxround << endl;
}
