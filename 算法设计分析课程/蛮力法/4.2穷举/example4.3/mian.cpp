#include<iostream>
using namespace std;
int main()
{
	int a, b, c, d, e;
	int m, n, sum;
	for (a = 0; a < 10; a++)//��
	{
		for (b = 0; b < 10; b++)//��
		{
			for (c = 0; c < 10; c++)//��
			{
				for (d = 0; d < 10; d++)//��
				{
					for (e = 0; e < 10; e++)//��
					{
						m = d * 1000 + c * 100 + b * 10 + a;
						n = d * 1000 + c * 100 + e * 10 + a;
						sum = e * 10000 + a * 1000 + b * 100 + d * 10 + a;
						if (m + n == sum&& sum != 0)
						{
							cout << "�䣺" << a << endl;
							cout << "��" << b << endl;
							cout << "�ڣ�" << c << endl;
							cout << "����" << d << endl;
							cout << "����" << e << endl;
						}
					}
				}
			}
		}
	}

}