#include "Vector2i.h"
#include <iostream>



Vector2i::Vector2i()
	: Vector2i(0, 0) {}

Vector2i::Vector2i(const int& x, const int& y)
	: m_x(x), m_y(y) {}

Vector2i Vector2i::operator+(Vector2i& v2i) const
{
	return Vector2i(m_x + v2i.m_x, m_y + v2i.m_y);
}

Vector2i Vector2i::operator-(Vector2i& v2i) const
{
	return Vector2i(m_x - v2i.m_x, m_y - v2i.m_y);
}
void Vector2i::print()
{
	std::cout << m_x << " x : " << m_y << " y" << std::endl;
}
