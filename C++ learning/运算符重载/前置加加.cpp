#include"Integrater.h"
Integrater& Integrater:: operator ++ ()
{
	m_num++;
	return *this;
}