#pragma once
class dot
{
public:
	//设置x轴坐标
	void setx(double x);
	//设置y轴坐标
	void sety(double y);
	//读取x轴坐标
	double getx();
	//读取y轴坐标
	double gety();
private:
	double d_x;
	double d_y;
};
