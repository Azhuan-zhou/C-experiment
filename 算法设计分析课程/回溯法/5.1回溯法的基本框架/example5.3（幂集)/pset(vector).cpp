#include<iostream>
#include<vector>
#define MAX 3
using namespace std;
const int a[] = { 1,2,3 };
const int n = MAX;
void disp(vector<int> ps)//�����̬����
{
	cout << " { ";
	for (int i=0;i<ps.size();i++)
	{
		cout << " " << ps[i] << " ";
	}
	cout << " } ";
}
void pset(int i, const int a[], vector<int>& ps)//iΪ���ĸ߶ȣ�a[]�Ǵ����ݼ�Ԫ�ص����飬psΪ��̬����
{
	if (i >= n)
	{
		disp(ps);
	}
	else
	{
		pset(i + 1, a, ps);//��֦
		ps.push_back(a[i]);
		pset(i + 1, a, ps);//��֦
	}
}
int main()
{
	vector<int> ps;
	cout << "1~3���ݼ���" << endl;
	pset(0, a , ps);
}