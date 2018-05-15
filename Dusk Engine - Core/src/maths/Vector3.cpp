#include "Vector3.h"
#include <memory>

Dusk::Maths::Vector3::Vector3(double x, double y, double z)
{
	this->x = m_C[0] = x;
	this->y = m_C[1] = y;
	this->z = m_C[2] = z;
}
