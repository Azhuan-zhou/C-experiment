#include<iostream>
using namespace std;
int n=10;//10分钱
int x, y, z;//分别代表1分钱，2分钱，5分钱的个数
int count = 1;
void disp()
{
	if (z != 0 && y != 0 && x != 0)
	{
		cout << "五分钱：" << z << "个，" << "两分钱：" << y << "个，" << "一分钱：" << x << "个。" << endl;
	}
	if(z != 0 && y != 0 &&x == 0)
	{
		cout << "五分钱：" << z << "个，" << "两分钱：" << y << "个，" << endl;
	}
	if(z != 0 && x==0 && y==0)
	{
		cout << "五分钱：" << z << "个，" << endl;
	}
	
}
void solve()
{
	for (z = 0; z <= n / 5; z++)//5分钱的个数
	{
		int t = (n - z * 5) / 2;
		for (y = 0; y <= t; y++)//2分钱的个数
		{
			if (5 * z + 2 * y < n)
			{
				x = n - (5 * z + 2 * y);//1分钱的个数
				cout <<"兑法"<<::count++<< ": 五分钱硬币" << z << "个，" << " 两分钱硬币" << y << "个，" << " 一分钱硬币" << x << "个" << endl;
			}
			else
			{
				x = 0;
				if (y != 0)
				{
					cout << "兑法" << ::count++<< ": 五分钱硬币" << z << "个，" << " 两分钱硬币" << y << "个" << endl;
				}
				else
				{
					cout <<"兑法" << ::count++ << ": 五分钱硬币" << z << "个" << endl;
				}
			}
		}
	}
}
int main()
{
	cout << "求解结果" << endl;
	solve();
	cout << "一共" << ::count-1 << "种兑法" << endl;
}