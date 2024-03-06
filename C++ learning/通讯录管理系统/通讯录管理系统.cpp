#include<iostream>
#include<string>
#define MAX 1000
using namespace std;
struct person//人员信息
{
	string name;//姓名
	string sex;//性别
	int age;//年龄
	string phone;//电话号码
	string address;//联系人地址
};
struct Addressbooks
{
	person personArray[MAX];
	int size;
};
void addperson(Addressbooks* p)//添加联系人
{
	//1.输入联系人姓名
	cout << "请输入姓名：" << endl;
	string name;
	cin >> name;
	p->personArray[p->size].name = name;
	//2.输入联系人性别
	cout<< "请输入性别：" << endl;
	string sex;
	cin >> sex;
	p->personArray[p->size].sex = sex;
	//3.输入联系人年龄
	cout << "请输入年龄：" << endl;
	int age;
	cin >> age;
	p->personArray[p->size].age = age;
	//4.输入联系人电话号码
	cout << "请输入电话号码：" << endl;
	string phone;
	cin >> phone;
	p->personArray[p->size].phone = phone;
	//5.输入联系人联系人地址
	cout << "请输入联系人地址：" << endl;
	string address;
	cin >> address;
	p->personArray[p->size].address =address;
	p->size++;
	cout << "输入成功" << endl;
	system("pause");
	system("cls");
}
void showperson(Addressbooks* p)//显示联系人
{
	if (p->size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < p->size; i++)
		{
			cout << "姓名：" << p->personArray[i].name << "\t";
			cout << "性别：" << p->personArray[i].sex << "\t";
			cout << "年龄：" << p->personArray[i].age << "\t";
			cout << "电话号码：" << p->personArray[i].phone << "\t";
			cout << "住址：" << p->personArray[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}
int isExist(Addressbooks* p,string name)//用姓名判度联系人是否存在
{
	for (int i = 0; i < p->size; i++)
	{
		if (p->personArray[i].name == name)
		{
			return i;
		}
	}
	return -1;
}
void deleteperson(Addressbooks* p, string name)//用姓名删除某个联系人的信息
{
	int ret = isExist(p, name);
	if (ret == -1)
	{
		cout << "通讯录中没有此人" << endl;
	}
	else
	{
		for (int i = ret; i < p->size-1; i++)
		{
			p->personArray[i].name = p->personArray[i + 1].name;
			p->personArray[i].sex = p->personArray[i + 1].sex;
			p->personArray[i].age = p->personArray[i + 1].age;
			p->personArray[i].phone = p->personArray[i + 1].phone;
			p->personArray[i].address = p->personArray[i + 1].address;
		}
		p->size--;
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}
void findperson(Addressbooks* p, string name)//查找联系人
{
	int ret = isExist( p, name);
	if (ret == -1)
	{
		cout << "通讯录中查无此人" << endl;
	}
	else
	{
		cout << "姓名：" << p->personArray[ret].name << "\t";
		cout << "性别：" << p->personArray[ret].sex << "\t";
		cout << "年龄：" << p->personArray[ret].age << "\t";
		cout << "电话号码：" << p->personArray[ret].phone << "\t";
		cout << "住址：" << p->personArray[ret].address << endl;
		cout << "查找成功" << endl;
	}
	system("pause");
	system("cls");
}
void reviseperson(Addressbooks* p, string name)//修改联系人
{
	int ret = isExist(p, name);
	if (ret == -1)
	{
		cout << "通讯录中查无此人" << endl;
	}
	else
	{
		string name;
		cout << "姓名：" << endl;
		cin >> name;
		p->personArray[ret].name = name;
		string sex;
		cout << "性别：" << endl;
		cin >> sex;
		p->personArray[ret].sex = sex;
		int age;
		cout << "年龄：" << endl;
		cin >> age;
		p->personArray[ret].age = age;
		string phone;
		cout << "电话号码：" << endl;
		cin >> phone;
		p->personArray[ret].phone = phone;
		string address;
		cout << "住址：" << endl;
		cin >> address;
		p->personArray[ret].address = address;
		cout << "修改成功" << endl;
	}
	system("pause");
	system("cls");
}
void clearall(Addressbooks *p)
{
	p->size = 0;
	cout << "通讯录已经清空" << endl;
	system("pause");
	system("cls");
}
void showmanu()
{
	cout << "**********************"<<endl;
	cout << "*****1.添加联系人*****" << endl;
	cout << "*****2.显示联系人*****" << endl;
	cout << "*****3.删除联系人*****" << endl;
	cout << "*****4.查找联系人*****" << endl;
	cout << "*****5.修改联系人*****" << endl;
	cout << "*****6.清空联系人*****" << endl;
	cout << "*****0.退出通讯录*****" << endl;
	cout << "**********************" << endl;
}
int main()
{
	int select;
	Addressbooks books;
	books.size = 0;
	while (true)
	{
		showmanu();
		cin >> select;
		switch (select)
		{
		case 1:
			addperson(&books);
			break;
		case 2:
			showperson(&books);
			break;
		case 3:
		{
			string name;
			cout << "请输入要删除联系人的姓名：" << endl;
			cin >> name;
			deleteperson(&books, name);
		}
			break;
		case 4:
		{
			string name;
			cout << "请输入要查找联系人的姓名：" << endl;
			cin >> name;
			findperson(&books, name);
		}
			break;
		case 5:
		{
			string name;
			cout << "请输入要修改联系人的姓名：" << endl;
			cin >> name;
			reviseperson(&books, name);
		}
			break;
		case 6:
			clearall(&books);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
		}
	}
	return 0;
}