#include<iostream>
#include<string>
using namespace std;
class phone
{
public:
	phone(string pname,int price):m_pname(pname),m_price(price)
	{
		cout << "����phone���캯��" << endl;
	}
	~phone()
	{
		cout << "����phone��������" << endl;
	}
	string m_pname;
	int m_price;
};
class person
{
public:
	person(string name, string phone,int price) :m_name(name),m_phone(phone,price)//������phone m_phone(phone , price)���캯��Ϊphone����ֵ���ٽ���person�ĸ���ֵ
	{
		cout << "����person���캯��" << endl;
	}
	~person()
	{
		cout << "����person��������" << endl;
	}
	string m_name;
	phone m_phone;
};
void test1()
{
	person p1("��ʥ��", "iphone14pro", 8000);
	cout << p1.m_name << " " << p1.m_phone.m_pname << " " << p1.m_phone.m_price << endl;
}
int main()
{
	test1();
}
