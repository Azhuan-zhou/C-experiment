#pragma once
#include<cmath>
#include<iostream>
#include"dot.h"
using namespace std;
class circle
{
public:
	//设置圆的圆心
	void setdot(dot& d);
	//设置圆的半径
	void setR(double r);
	//读取圆的圆心
	dot getdot();
	//读取圆的半径;;
	double getR();
	double distance(dot& d);
	void relation(dot& d);
private:
	double c_R;
	dot c_dot;
};
