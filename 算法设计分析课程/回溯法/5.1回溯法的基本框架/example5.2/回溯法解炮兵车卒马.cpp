#include<iostream>
#include<string>
using namespace std;
int main()
{
	int name[10] = { 0 };
	int a, b, c, d, e;
	int m, n, s;
	for (a = 0; a <= 9; a++)//��
	{
		name[a] = 1;
		for (b = 0; b <= 9; b++)//��
		{
			if (name[b] == 0)
			{
				name[b] = 1;
				for (c = 0; c <= 9; c++)//��
				{
					if (name[c] == 0)
					{
						name[c] = 1;
						for (d = 0; d <= 9; d++)//��
						{
							if (name[d] == 0)
							{
								name[d] = 1;
								for (e = 0; e <= 9; e++)//��
								{
									if (name[e] == 0)
									{
										name[e] = 1;
										m = b * 1000 + d * 100 + e * 10 + a;
										n = b * 1000 + d * 100 + c * 10 + a;
										s = c * 10000 + a * 1000 + e * 100 + b * 10 + a;

									}
									if(s==m+n)
									{
										cout << "��:" << a << " ��: " << b << " ��: " << c << " ��: " << d << " ��:" << e;

									}
									name[e] = 0;
								}
							}
							name[d] = 0;
						}
					}
					name[c] = 0;
				}
				
			}
			name[b] = 0;
		}
		name[a] = 0;
	}
}