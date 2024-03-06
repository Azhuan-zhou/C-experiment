#include"head.h"
int main()
{
	int a[] = {1,2,3};
	int b[] = { 0,0,0 };
	int n = sizeof(a) / sizeof(int);
	pset(a, b,n);
}