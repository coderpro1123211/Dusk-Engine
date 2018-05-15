#include "Vector3.h"
#include <memory>

Dusk::Maths::Vector3::Vector3(double x, double y, double z)
{
	m_C[0] = x;
	m_C[1] = y;
	m_C[2] = z;
}
