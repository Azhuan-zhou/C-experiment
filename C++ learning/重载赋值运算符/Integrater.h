#pragma once
#include<iostream>
using namespace std;
class Integrater
{
friend ostream& operator<<(ostream& cout, Integrater& num);
public:
	Integrater(int a);
	Integrater operator=(Integrater &num);
private:
	int m_num;
};
ostream& operator<<(ostream& cout, Integrater &num);