#include"Integrater.h"
int main()
{
	Integrater num = 10;
	Integrater num1=num.operator++();
	cout << num1 << endl;
	cout << (int) & num1 << endl;
	cout << num << endl;
	cout << (int) & num << endl;
}