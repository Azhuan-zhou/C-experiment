#include<iostream>
using namespace std;
int main()
{
	int a, b, c, d, e;
	int m, n, sum;
	for (a = 0; a < 10; a++)//卒
	{
		for (b = 0; b < 10; b++)//马
		{
			for (c = 0; c < 10; c++)//炮
			{
				for (d = 0; d < 10; d++)//兵
				{
					for (e = 0; e < 10; e++)//车
					{
						m = d * 1000 + c * 100 + b * 10 + a;
						n = d * 1000 + c * 100 + e * 10 + a;
						sum = e * 10000 + a * 1000 + b * 100 + d * 10 + a;
						if (m + n == sum&& sum != 0)
						{
							cout << "卒：" << a << endl;
							cout << "马：" << b << endl;
							cout << "炮：" << c << endl;
							cout << "兵：" << d << endl;
							cout << "车：" << e << endl;
						}
					}
				}
			}
		}
	}

}