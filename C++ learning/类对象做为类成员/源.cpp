#include<iostream>
#include<string>
using namespace std;
class phone
{
public:
	phone(string pname,int price):m_pname(pname),m_price(price)
	{
		cout << "调用phone构造函数" << endl;
	}
	~phone()
	{
		cout << "调用phone析构函数" << endl;
	}
	string m_pname;
	int m_price;
};
class person
{
public:
	person(string name, string phone,int price) :m_name(name),m_phone(phone,price)//先利用phone m_phone(phone , price)构造函数为phone赋初值，再进行person的赋初值
	{
		cout << "调用person构造函数" << endl;
	}
	~person()
	{
		cout << "调用person析构函数" << endl;
	}
	string m_name;
	phone m_phone;
};
void test1()
{
	person p1("周圣涵", "iphone14pro", 8000);
	cout << p1.m_name << " " << p1.m_phone.m_pname << " " << p1.m_phone.m_price << endl;
}
int main()
{
	test1();
}
