#include"circle.h"
#include"dot.h"
int main()
{
	dot d1;
	dot d2;
	dot d3;
	dot c_d;
	circle c;
	d1.setx(6);
	d1.sety(8);
	cout << "点1的坐标为（" << d1.getx() << "," << d1.gety() << ")" << endl;
	d2.setx(3);
	d2.sety(4);
	cout << "点2的坐标为（" << d2.getx() << "," << d2.gety() << ")" << endl;
	d3.setx(1);
	d3.sety(2);
	cout << "点3的坐标为（" << d3.getx() << "," << d3.gety() << ")" << endl;
	c_d.setx(0);
	c_d.sety(0);
	cout << "圆心的坐标为（" << c_d.getx() << "," << c_d.gety() << ")" << endl;
	c.setdot(c_d);
	c.setR(5);
	cout << "点1和圆的关系:";
	c.relation(d1);
	cout << "点2和圆的关系:";
	c.relation(d2);
	cout << "点3和圆的关系:";
	c.relation(d3);
}



