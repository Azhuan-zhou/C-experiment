#include<iostream>
using namespace std;
int main()
{
	int num;
	int i, j;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			num = 1000 * i + 100 * j + 10 + 2;
			if ((num - 7) % 7 == 0 && (num - 8) % 8 == 0 && (num - 9) % 9 == 0)
			{
				cout << num << " ";
			}
		}
	}

}