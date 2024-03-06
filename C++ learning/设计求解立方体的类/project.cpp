#include<iostream>
using namespace std;
class cube
{
public:
	//设置长度
	void setl(int l)
	{
		m_l = l;
	}
	//获取长度
	int getl()
	{
		return m_l;
	}
	//设置宽度
	void setw(int w)
	{
		m_w = w;
	}
	//获取宽度
	int getw()
	{
		return m_w;
	}
	//设置高度
	void seth(int h)
	{
		m_h = h;
	}
	//获取宽度
	int geth()
	{
		return m_h;
	}
	//获取面积
	int calculateS()
	{
		return 2 * m_h * m_l + 2 * m_h * m_w + 2 * m_l * m_w;
	}
	//获取体积
	int calculateV()
	{
		return m_l * m_w * m_h;
	}
	bool isSame(cube& c)
	{
		if (m_l == c.m_l && m_h == c.m_h && m_w == c.m_w)
		{
			return true;
		}
		return false;
	}
private:
	int m_l;
	int m_h;
	int m_w;
};
int main()
{
	cube C1;
	C1.setl(10);
	C1.seth(10);
	C1.setw(10);
	cube C2;
	cout << "C1面积：" << C1.calculateS() << endl;
	cout << "C2体积：" << C1.calculateV() << endl;
	C2.setl(10);
	C2.setw(10);
	C2.seth(10);
	bool ret = C1.isSame(C2);
	if (ret)
	{
		cout << "立方体C1和C2相等" << endl;
	}
}