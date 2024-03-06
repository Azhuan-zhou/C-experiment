#include"head.h"
void merge(int a[], int low, int mid, int high)
{
	int i = low;//形参数组最左边的下标
	int j = mid+1;//形参数组中间的下标
	int k, l;
	int t = 0;//临时数组的下标
	vector<int> p(high - low + 1);
	//创建长度为（high-low+1）的一维临时数组
	while (i <= mid && j <= high)//两个分块的数组a[i],a[j],将元素依次进行两两比较，小的放入临时数组p中
	{
		if (a[i] <= a[j])
		{
			p[t] = a[i];
			i++;
			t++;
		}
		else
		{
			p[t] = a[j];
			j++;
			t++;
		}
	}
	while (i <=  mid)//如果数组a[i]剩下一个元素,则放入临时数组中
	{
		p[t] = a[i];
		i++;
		t++;
	}
	while (j <= high)//如果数组a[j]剩下一个元素,则放入临时数组中
	{
		p[t] = a[j];
		j++;
		t++;
	}
	for (k = low, l = 0; k <= high ; k++, l++)//将排好序的数组放入a的第low个元素到第high个元素
	{
		a[k] = p [l];
	}
	cout << "执行了merge" << endl;
	print(a, 10);
	cout << endl;
}