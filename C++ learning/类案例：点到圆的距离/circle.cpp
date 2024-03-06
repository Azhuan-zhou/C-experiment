#include"circle.h"
#include"dot.h"
	//����Բ��Բ��
	void circle::setdot(dot& d)
	{
		c_dot = d;
	}
	//����Բ�İ뾶
	void circle::setR(double r)
	{
		c_R = r;
	}
	//��ȡԲ��Բ��
	dot circle::getdot()
	{
		return c_dot;
	}
	//��ȡԲ�İ뾶
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
			cout << "����Բ��" << endl;
		}
		else if (dist == c_R)
		{
			cout << "����Բ��" << endl;
		}
		else
		{
			cout << "����Բ��" << endl;
		}
	}
