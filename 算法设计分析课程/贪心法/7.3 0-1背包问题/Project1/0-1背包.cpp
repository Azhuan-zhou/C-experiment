#include<iostream>
#include<algorithm>
#include<iomanip>
#define MAX 20
using namespace std;
struct object
{
	int no;//物品编号
	double w;//物品重量
	double v;//物品价值
	bool operator<(const object& o)const
	{
		return v / w > o.v / o.w;
	}
};
int Weight = 100;//上限重量为100kg
object m[MAX] = { {0},{1,10,20},{2,20,30},{3,40,40},{4,30,66} ,{5,50,60} };
int n = 5;//五个物品
int x[MAX] = { 0 };//存放放入背包物品的编号
int Size[MAX];//存放放入背包物品的大小
int v = 0;//当前价值
int w = 0;//当前重量
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
		w =w- m[i].w;//当第i个物品装入背包后超重，则放入部分第i个物品
		v = v - m[i].v;
		v += (Weight - w) * (m[i].v / m[i].w);
		Size[i] = (Weight - w) / m[i].w;//赋值失败
		cout <<i<<endl;
		w = Weight;
	}

}
void disp()
{
	int i;
	cout <<setw(5)<<"序号" << setw(5) << "W" << setw(5) << "V" << setw(5) << "V/W"<<endl;
	for (i = 1; i <= n; i++)
	{
		cout <<setw(5)<<m[i].no<< setw(5) << m[i].w << setw(5) << m[i].v << setw(5) << m[i].v / m[i].w<<endl;
	}
}
int main()
{
	int i ;
	cout << "求解过程"<<endl;
	cout << "(1) 排序前：" << endl;
	disp();
	Knap();
	cout << "(2) 排序后：" << endl;
	disp();
	cout << "依次放入背包物品的编号为：";
	for (i = 1; i <= n; i++)
	{
		if (x[i] != 0)
		{
			cout << x[i] << " ";
		}
	}
	cout << endl;
	cout << "放入背包物品大小为："<<endl;
	for (i = 1; i <= n; i++)
	{
		if (x[i] != 0)
		{
			cout<<setw(8) <<"第"<<m[i].no<<"个物品放入"<< Size[i] << "个"<<endl;
		}
	}
	cout << "总价值：" << v;
}
