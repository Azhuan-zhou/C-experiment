#pragma once
#include<cmath>
#include<iostream>
#include"dot.h"
using namespace std;
class circle
{
public:
	//����Բ��Բ��
	void setdot(dot& d);
	//����Բ�İ뾶
	void setR(double r);
	//��ȡԲ��Բ��
	dot getdot();
	//��ȡԲ�İ뾶;;
	double getR();
	double distance(dot& d);
	void relation(dot& d);
private:
	double c_R;
	dot c_dot;
};
