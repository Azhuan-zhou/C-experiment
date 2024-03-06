#include"circle.h"
#include"dot.h"
	//设置圆的圆心
	void circle::setdot(dot& d)
	{
		c_dot = d;
	}
	//设置圆的半径
	void circle::setR(double r)
	{
		c_R = r;
	}
	//读取圆的圆心
	dot circle::getdot()
	{
		return c_dot;
	}
	//读取圆的半径
	double circle::getR()
	{
		return c_R;
	}
	double circle::distance(dot& d)
	{
		double d_x = d.getx();
		double d_y = d.gety();
		double r_x = c_dot.getx();
		double r_y = c_dot.gety();
		double dist;
		dist = sqrt((d_x - r_x) * (d_x - r_x) + (d_y - r_y) * (d_y - r_y));
		return dist;
	}
	void circle::relation(dot& d)
	{
		double dist = distance(d);
		if (dist < c_R)
		{
			cout << "点在圆内" << endl;
		}
		else if (dist == c_R)
		{
			cout << "点在圆上" << endl;
		}
		else
		{
			cout << "点在圆外" << endl;
		}
	}
