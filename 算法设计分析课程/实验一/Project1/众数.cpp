#include<iostream>
using namespace std;
int num;//众数
int maxcnt = 0;//重数
int a[] = {1,2,2,3,3,3,5,6,6,6,6};
void split(int low, int high, int& mid, int& right, int& left)
{
	mid = (low + high) / 2;
	for (left = mid; left >= low; left--)//找到第一个和a[mid]元素相同的元素位置,用left储存
	{
		if (a[left] != a[mid])
		{
			break;
		}
	}
	left++;
	for(right = left; right <= high; right++)//找到元素a[left]后与a[mid]元素不相同的元素位置,用left储存
	{
		if (a[right] != a[mid])
		{
			break;
		}
	}
	right--;
}
void Getmaxcnt(int low, int high)
{
	if (low <= high)
	{
		int cnt;
		int mid, left, right;
		split(low, high, mid, right, left);//求解出left和righ位置
		cnt = right - left + 1;//计算出重数
		if (cnt > maxcnt)
		{
			num = a[mid];
			maxcnt = cnt;
		}
		Getmaxcnt(low, left-1);//左序列
		Getmaxcnt(right+1, high);//右序列
	}
}
int main()
{
	int low = 0;
	int high = sizeof(a) / sizeof(int)-1;
	cout << "求解结果"<<endl;
	cout << "递增序列：";
	for (int i = 0; i <= high; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	Getmaxcnt(low, high);
	cout << "众数：" << num << ",重数：" << maxcnt;
}