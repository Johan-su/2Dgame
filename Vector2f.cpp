#include "Vector2f.h"
#include <iostream>



Vector2f::Vector2f()
	: Vector2f(0.0f, 0.0f) {}

Vector2f::Vector2f(const float& x, const float& y)
: m_x(x), m_y(y) {}

Vector2f Vector2f::operator+(Vector2f& v2f) const
{	
	return Vector2f(m_x + v2f.m_x, m_y + v2f.m_y);
}

Vector2f Vector2f::operator-(Vector2f& v2f) const
{
	return Vector2f(m_x - v2f.m_x, m_y - v2f.m_y);
}


void Vector2f::print()
{
	std::cout << "(" << m_x << ", " << m_y << ")" << std::endl;
}
