#pragma once
#include<iostream>
using namespace std;
class Integrater
{
	friend ostream& operator<<(ostream& cout, Integrater& in);
public:
	Integrater(int a);
	Integrater& operator ++ ();
	Integrater operator ++(int);
private:
	int m_num;
};
ostream& operator<<(ostream& cout, Integrater& num);