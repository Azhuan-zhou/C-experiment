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
	cout << "��1������Ϊ��" << d1.getx() << "," << d1.gety() << ")" << endl;
	d2.setx(3);
	d2.sety(4);
	cout << "��2������Ϊ��" << d2.getx() << "," << d2.gety() << ")" << endl;
	d3.setx(1);
	d3.sety(2);
	cout << "��3������Ϊ��" << d3.getx() << "," << d3.gety() << ")" << endl;
	c_d.setx(0);
	c_d.sety(0);
	cout << "Բ�ĵ�����Ϊ��" << c_d.getx() << "," << c_d.gety() << ")" << endl;
	c.setdot(c_d);
	c.setR(5);
	cout << "��1��Բ�Ĺ�ϵ:";
	c.relation(d1);
	cout << "��2��Բ�Ĺ�ϵ:";
	c.relation(d2);
	cout << "��3��Բ�Ĺ�ϵ:";
	c.relation(d3);
}



