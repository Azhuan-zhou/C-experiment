#include<iostream>
using namespace std;
int partition(int a[],int low, int high)//寻找a[Low]元素在排序后数组的下标位置
{
	int i = low;//左下标
	int j = high;//右下标
	int t = a[low];//第一个位置元素
	while (i < j)//当循环后左下标j不等于右下标i，继续循环
	{
		while (i < j && a[j] >= t)
		{
			j--;//从右往左，大于第一个元素时j减1
		}
		while (i < j && a[i] <= t)
		{
			i++;
		}
		//当在左边找到小于a[low]的元素时，在右边找到大于a[low]的元素时，交换两个元素的位置
		int k = a[j];
		a[j] = a[i];
		a[i] = k;
	}
	a[low] = a[i];
	a[i] = t;
	return i;
}
int solve(int a[],int n)
{
	int i;
	int low = 0;
	int high = n - 1;
	bool flag = true;//用来判断快速排序时，第low个元素，是否是整个数组排序后的中间位置
	while (flag)
	{
		i = partition(a,low, high);
		if (i == n / 2-1)
		{
			flag = false;
		}
		else if (i < n / 2-1)
		{
			low = i + 1;
		}
		else
		{
			high = i - 1;
		}
	}
	int s1 = 0;//中间位置的左序列求和
	int s2 = 0;//中间位置的右序列求和
	for (int j1 = 0; j1 < n/2; j1++)
	{
		s1 += a[j1];
	}
	for (int j2 = n/2; j2 < n ; j2++)
	{
		s2 += a[j2];
	}
	return s2 - s1;
	
}
void disp(int a[],int low, int high)
{
	for (int i = low; i <= high; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
int main()
{
	int a[] = { 1,3,5,7,9,2,4,6,8 };
	int b[] = { 1,3,5,7,9,10,2,4,6,8 };
	int result1, result2;
	int n1, n2;
    //a
	n1 = sizeof(a) / sizeof(int);
	cout << "初始序列A：";
	disp(a,0,n1-1);
	result1=solve(a,n1);
	cout << "求解结果："<<result1<<endl;
	cout << "划分结果 A1:";
	disp(a,0, n1 / 2-1);
	cout << "         A2:";
	disp(a,n1 / 2 , n1 - 1);
    //b
	n2 = sizeof(b) / sizeof(int);
	cout << "初始序列B：";
	disp(b,0, n2 - 1);
	result2 = solve(b, n2);
	cout << "求解结果：" << result2 << endl;
	cout << "划分结果 A1:";
	disp(b,0, n2 / 2 - 1);
	cout << "         A2:";
	disp(b,n2 / 2, n2 - 1);
}