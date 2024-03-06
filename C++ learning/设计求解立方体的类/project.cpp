#include<iostream>
using namespace std;
class cube
{
public:
	//���ó���
	void setl(int l)
	{
		m_l = l;
	}
	//��ȡ����
	int getl()
	{
		return m_l;
	}
	//���ÿ��
	void setw(int w)
	{
		m_w = w;
	}
	//��ȡ���
	int getw()
	{
		return m_w;
	}
	//���ø߶�
	void seth(int h)
	{
		m_h = h;
	}
	//��ȡ���
	int geth()
	{
		return m_h;
	}
	//��ȡ���
	int calculateS()
	{
		return 2 * m_h * m_l + 2 * m_h * m_w + 2 * m_l * m_w;
	}
	//��ȡ���
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
	cout << "C1�����" << C1.calculateS() << endl;
	cout << "C2�����" << C1.calculateV() << endl;
	C2.setl(10);
	C2.setw(10);
	C2.seth(10);
	bool ret = C1.isSame(C2);
	if (ret)
	{
		cout << "������C1��C2���" << endl;
	}
}