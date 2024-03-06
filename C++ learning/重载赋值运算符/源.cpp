#include"Integrater.h"
int main()
{
	int Count=1;
	Integrater num1(10);
	Integrater num2(23);
	Integrater num3(33);
	Integrater num4(15);
	cout << "第" << Count++ << "次赋值" << endl;
	num3 = num4;
	cout << "第" << Count++ << "次赋值" << endl;
	num2 = num3;
	cout << "第" << Count++ << "次赋值" << endl;
	num1 = num2;
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;
	cout << num4 << endl;
}