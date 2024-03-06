#include<iostream>
using namespace std;
void swap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	printf("a=%d,b=%d\n", a, b);
}
void swap02(int *a, int *b)
{
	cout << a << "  " << b << endl;
	int *temp = a;
	a = b;
	b = temp;
	cout << a << "  " << b << endl;
	printf("a=%d,b=%d\n", *a, *b);//只改变了指针a,b的指向，并没有利用指针直接对地址进行操作
}
void swap03(int* a, int* b)
{
	cout << a << "  " << b << endl;
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("a=%d,b=%d\n", *a, *b);//改变了指针a,b指向地址的值，并没有改变指针的指向
	cout << a << "  " << b << endl;
}
int main()
{
	int a = 10, b = 20;
	swap01(a, b);
	printf("调用swap01后，a=%d,b=%d\n", a, b);
	a = 10, b = 20;
	swap02(&a, &b);
	printf("调用swap02后，a=%d,b=%d\n", a, b);
	swap03(&a, &b);
	printf("调用swap03后，a=%d,b=%d\n", a, b);

}
