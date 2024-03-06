#include<iostream>
#define N 9
using namespace std;
const int a[N] = { 1,2,3,4,5,6,7,8,9 };
void dispsolution(char op[])//输出
{
	cout << a[0];
	for (int i = 1; i < 9; i++)
	{	
		if (op[i] != ' ')
		{
			cout << op[i];
		}
		cout << a[i];
	}
	cout << "=100" << endl;
}
void fun(int i, char op[], int sum, int num)
{
	if (i == N)
	{
		if(sum==100)
		{
			dispsolution(op);
		}
		//return;
	}
	else//从第二个元素开始
	{
		//插入'+'
		op[i] = '+';
		sum += a[i];//sum加上a[i]元素
		fun(i + 1, op, sum, a[i]);
		sum -= a[i];//回溯
		//插入'-'
		op[i] = '-';
		sum -= a[i];//sum减去a[i]元素
		fun(i + 1, op, sum, -a[i]);
		sum += a[i];//回溯
		//插入' '
		op[i] = ' ';
		sum -= num;//如果插入空格，则需要把上一次给sum加上或者减去的num给去掉
		int temp;
		if (num > 0)
		{
			temp = num * 10 + a[i];
		}
		else
		{
			temp = num * 10 - a[i];
		}
		sum += temp; 
		fun(i + 1, op, sum, temp);
		sum -= temp;//回溯
		sum += num;//将之前删去的num补回来
	}
}
int main()
{
	char op[N];
	cout << "求解结果：" << endl;
	fun(1, op, a[0], a[0]);
}