#include<iostream>
using namespace std;
int partition(int a[],int low, int high)//Ѱ��a[Low]Ԫ���������������±�λ��
{
	int i = low;//���±�
	int j = high;//���±�
	int t = a[low];//��һ��λ��Ԫ��
	while (i < j)//��ѭ�������±�j���������±�i������ѭ��
	{
		while (i < j && a[j] >= t)
		{
			j--;//�������󣬴��ڵ�һ��Ԫ��ʱj��1
		}
		while (i < j && a[i] <= t)
		{
			i++;
		}
		//��������ҵ�С��a[low]��Ԫ��ʱ�����ұ��ҵ�����a[low]��Ԫ��ʱ����������Ԫ�ص�λ��
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
	bool flag = true;//�����жϿ�������ʱ����low��Ԫ�أ��Ƿ������������������м�λ��
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
	int s1 = 0;//�м�λ�õ����������
	int s2 = 0;//�м�λ�õ����������
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
	cout << "��ʼ����A��";
	disp(a,0,n1-1);
	result1=solve(a,n1);
	cout << "�������"<<result1<<endl;
	cout << "���ֽ�� A1:";
	disp(a,0, n1 / 2-1);
	cout << "         A2:";
	disp(a,n1 / 2 , n1 - 1);
    //b
	n2 = sizeof(b) / sizeof(int);
	cout << "��ʼ����B��";
	disp(b,0, n2 - 1);
	result2 = solve(b, n2);
	cout << "�������" << result2 << endl;
	cout << "���ֽ�� A1:";
	disp(b,0, n2 / 2 - 1);
	cout << "         A2:";
	disp(b,n2 / 2, n2 - 1);
}