#include"Integrater.h"
Integrater Integrater::operator=(Integrater &num)
{
	cout << &num << endl;
	m_num = num.m_num;
	cout << this << endl;
	return *this;
}