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
	printf("a=%d,b=%d\n", *a, *b);//ֻ�ı���ָ��a,b��ָ�򣬲�û������ָ��ֱ�ӶԵ�ַ���в���
}
void swap03(int* a, int* b)
{
	cout << a << "  " << b << endl;
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("a=%d,b=%d\n", *a, *b);//�ı���ָ��a,bָ���ַ��ֵ����û�иı�ָ���ָ��
	cout << a << "  " << b << endl;
}
int main()
{
	int a = 10, b = 20;
	swap01(a, b);
	printf("����swap01��a=%d,b=%d\n", a, b);
	a = 10, b = 20;
	swap02(&a, &b);
	printf("����swap02��a=%d,b=%d\n", a, b);
	swap03(&a, &b);
	printf("����swap03��a=%d,b=%d\n", a, b);

}
