#include<iostream>
using namespace std;
int num;//����
int maxcnt = 0;//����
int a[] = {1,2,2,3,3,3,5,6,6,6,6};
void split(int low, int high, int& mid, int& right, int& left)
{
	mid = (low + high) / 2;
	for (left = mid; left >= low; left--)//�ҵ���һ����a[mid]Ԫ����ͬ��Ԫ��λ��,��left����
	{
		if (a[left] != a[mid])
		{
			break;
		}
	}
	left++;
	for(right = left; right <= high; right++)//�ҵ�Ԫ��a[left]����a[mid]Ԫ�ز���ͬ��Ԫ��λ��,��left����
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
		split(low, high, mid, right, left);//����left��righλ��
		cnt = right - left + 1;//���������
		if (cnt > maxcnt)
		{
			num = a[mid];
			maxcnt = cnt;
		}
		Getmaxcnt(low, left-1);//������
		Getmaxcnt(right+1, high);//������
	}
}
int main()
{
	int low = 0;
	int high = sizeof(a) / sizeof(int)-1;
	cout << "�����"<<endl;
	cout << "�������У�";
	for (int i = 0; i <= high; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	Getmaxcnt(low, high);
	cout << "������" << num << ",������" << maxcnt;
}