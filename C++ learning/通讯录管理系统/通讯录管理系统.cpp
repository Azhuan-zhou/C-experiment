#include<iostream>
#include<string>
#define MAX 1000
using namespace std;
struct person//��Ա��Ϣ
{
	string name;//����
	string sex;//�Ա�
	int age;//����
	string phone;//�绰����
	string address;//��ϵ�˵�ַ
};
struct Addressbooks
{
	person personArray[MAX];
	int size;
};
void addperson(Addressbooks* p)//�����ϵ��
{
	//1.������ϵ������
	cout << "������������" << endl;
	string name;
	cin >> name;
	p->personArray[p->size].name = name;
	//2.������ϵ���Ա�
	cout<< "�������Ա�" << endl;
	string sex;
	cin >> sex;
	p->personArray[p->size].sex = sex;
	//3.������ϵ������
	cout << "���������䣺" << endl;
	int age;
	cin >> age;
	p->personArray[p->size].age = age;
	//4.������ϵ�˵绰����
	cout << "������绰���룺" << endl;
	string phone;
	cin >> phone;
	p->personArray[p->size].phone = phone;
	//5.������ϵ����ϵ�˵�ַ
	cout << "��������ϵ�˵�ַ��" << endl;
	string address;
	cin >> address;
	p->personArray[p->size].address =address;
	p->size++;
	cout << "����ɹ�" << endl;
	system("pause");
	system("cls");
}
void showperson(Addressbooks* p)//��ʾ��ϵ��
{
	if (p->size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < p->size; i++)
		{
			cout << "������" << p->personArray[i].name << "\t";
			cout << "�Ա�" << p->personArray[i].sex << "\t";
			cout << "���䣺" << p->personArray[i].age << "\t";
			cout << "�绰���룺" << p->personArray[i].phone << "\t";
			cout << "סַ��" << p->personArray[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}
int isExist(Addressbooks* p,string name)//�������ж���ϵ���Ƿ����
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
void deleteperson(Addressbooks* p, string name)//������ɾ��ĳ����ϵ�˵���Ϣ
{
	int ret = isExist(p, name);
	if (ret == -1)
	{
		cout << "ͨѶ¼��û�д���" << endl;
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
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}
void findperson(Addressbooks* p, string name)//������ϵ��
{
	int ret = isExist( p, name);
	if (ret == -1)
	{
		cout << "ͨѶ¼�в��޴���" << endl;
	}
	else
	{
		cout << "������" << p->personArray[ret].name << "\t";
		cout << "�Ա�" << p->personArray[ret].sex << "\t";
		cout << "���䣺" << p->personArray[ret].age << "\t";
		cout << "�绰���룺" << p->personArray[ret].phone << "\t";
		cout << "סַ��" << p->personArray[ret].address << endl;
		cout << "���ҳɹ�" << endl;
	}
	system("pause");
	system("cls");
}
void reviseperson(Addressbooks* p, string name)//�޸���ϵ��
{
	int ret = isExist(p, name);
	if (ret == -1)
	{
		cout << "ͨѶ¼�в��޴���" << endl;
	}
	else
	{
		string name;
		cout << "������" << endl;
		cin >> name;
		p->personArray[ret].name = name;
		string sex;
		cout << "�Ա�" << endl;
		cin >> sex;
		p->personArray[ret].sex = sex;
		int age;
		cout << "���䣺" << endl;
		cin >> age;
		p->personArray[ret].age = age;
		string phone;
		cout << "�绰���룺" << endl;
		cin >> phone;
		p->personArray[ret].phone = phone;
		string address;
		cout << "סַ��" << endl;
		cin >> address;
		p->personArray[ret].address = address;
		cout << "�޸ĳɹ�" << endl;
	}
	system("pause");
	system("cls");
}
void clearall(Addressbooks *p)
{
	p->size = 0;
	cout << "ͨѶ¼�Ѿ����" << endl;
	system("pause");
	system("cls");
}
void showmanu()
{
	cout << "**********************"<<endl;
	cout << "*****1.�����ϵ��*****" << endl;
	cout << "*****2.��ʾ��ϵ��*****" << endl;
	cout << "*****3.ɾ����ϵ��*****" << endl;
	cout << "*****4.������ϵ��*****" << endl;
	cout << "*****5.�޸���ϵ��*****" << endl;
	cout << "*****6.�����ϵ��*****" << endl;
	cout << "*****0.�˳�ͨѶ¼*****" << endl;
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
			cout << "������Ҫɾ����ϵ�˵�������" << endl;
			cin >> name;
			deleteperson(&books, name);
		}
			break;
		case 4:
		{
			string name;
			cout << "������Ҫ������ϵ�˵�������" << endl;
			cin >> name;
			findperson(&books, name);
		}
			break;
		case 5:
		{
			string name;
			cout << "������Ҫ�޸���ϵ�˵�������" << endl;
			cin >> name;
			reviseperson(&books, name);
		}
			break;
		case 6:
			clearall(&books);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
		}
	}
	return 0;
}