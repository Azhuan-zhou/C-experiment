#include<iostream>
#include<algorithm>
#include<iomanip>
#define MAX 20
using namespace std;
struct object
{
	int no;//��Ʒ���
	double w;//��Ʒ����
	double v;//��Ʒ��ֵ
	bool operator<(const object& o)const
	{
		return v / w > o.v / o.w;
	}
};
int Weight = 100;//��������Ϊ100kg
object m[MAX] = { {0},{1,10,20},{2,20,30},{3,40,40},{4,30,66} ,{5,50,60} };
int n = 5;//�����Ʒ
int x[MAX] = { 0 };//��ŷ��뱳����Ʒ�ı��
int Size[MAX];//��ŷ��뱳����Ʒ�Ĵ�С
int v = 0;//��ǰ��ֵ
int w = 0;//��ǰ����
void Knap()
{
	sort(m, m + n + 1);
	int i = 0;
	while (w <= Weight && i<=n)
	{
		i++;
		w += m[i].w;
		x[i] = m[i].no;
		Size[i] = 1;
		v += m[i].v;
	}
	int t;
	if (w > Weight)
	{
		w =w- m[i].w;//����i����Ʒװ�뱳�����أ�����벿�ֵ�i����Ʒ
		v = v - m[i].v;
		v += (Weight - w) * (m[i].v / m[i].w);
		Size[i] = (Weight - w) / m[i].w;//��ֵʧ��
		cout <<i<<endl;
		w = Weight;
	}

}
void disp()
{
	int i;
	cout <<setw(5)<<"���" << setw(5) << "W" << setw(5) << "V" << setw(5) << "V/W"<<endl;
	for (i = 1; i <= n; i++)
	{
		cout <<setw(5)<<m[i].no<< setw(5) << m[i].w << setw(5) << m[i].v << setw(5) << m[i].v / m[i].w<<endl;
	}
}
int main()
{
	int i ;
	cout << "������"<<endl;
	cout << "(1) ����ǰ��" << endl;
	disp();
	Knap();
	cout << "(2) �����" << endl;
	disp();
	cout << "���η��뱳����Ʒ�ı��Ϊ��";
	for (i = 1; i <= n; i++)
	{
		if (x[i] != 0)
		{
			cout << x[i] << " ";
		}
	}
	cout << endl;
	cout << "���뱳����Ʒ��СΪ��"<<endl;
	for (i = 1; i <= n; i++)
	{
		if (x[i] != 0)
		{
			cout<<setw(8) <<"��"<<m[i].no<<"����Ʒ����"<< Size[i] << "��"<<endl;
		}
	}
	cout << "�ܼ�ֵ��" << v;
}
