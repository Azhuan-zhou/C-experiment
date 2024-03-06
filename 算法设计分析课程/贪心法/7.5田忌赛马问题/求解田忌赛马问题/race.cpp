#include<iostream>
#include<iomanip>
#include<algorithm>
#define MAX 20
using namespace std;
int a[MAX];//田忌的马
int b[MAX];//齐威王的马
int n;//马的总数
int money;
void solve()
{
	money = 0;
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	int lefta = 1, leftb = 1;//慢马
	int righta = n, rightb = n;//快马
	while (lefta <= righta)
	{
		if (a[righta] > b[rightb])//田忌的快马速度大于齐威王的快马速度
		{
			righta--;//用田忌最快的马和齐威王最快的马比赛
			rightb--;
			money += 200;
		}
		else if (a[righta] < b[rightb])//田忌的快马速度小于于齐威王的快马速度
		{
			lefta++;//用田忌最慢的马和齐威王最快的马比赛
			rightb--;
			money -= 200;
		}
		else
		{
			if (a[lefta] > b[leftb])//田忌的慢马速度大于于齐威王的慢马速度
			{
				lefta++;//用田忌最慢的马和齐威王最慢的马比赛
				leftb++;
				money += 200;
			}
			else if(a[lefta]<b[leftb])//田忌的慢马速度小于于齐威王的慢马速度
			{
				lefta++;
				leftb++;
				money -= 200;
			}
			else
			{
				lefta++;
				leftb++;
			}
		}
	}
}
void disp()
{
	cout << "田忌赢得得钱：" << money;
}
int main()
{
	while (true)
	{
		cin >> n;
		if (n == 0)
		{
			break;
		}
		for (int i = 1; i <= n; i++)//输入田忌马的速度
		{
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++)//输入齐威王马的速度
		{
			cin >> b[i];
		}
		solve();
		disp();
	}
	
}