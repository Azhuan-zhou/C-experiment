#include<iostream>
using namespace std;
int test01()
{
	static int b = 10;
	return b;
}
int main()
{
	int b = 10;
	int& a = test01();
	cout << "mainÖĞaµÄµØÖ·" << &a;

}