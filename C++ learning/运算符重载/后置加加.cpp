#include"Integrater.h"
Integrater Integrater::operator ++(int)
{f
	Integrater temp=*this;
	m_num++;
	return temp;
}