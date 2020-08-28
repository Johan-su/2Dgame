#pragma once
#include <cmath>
class Vector2f
{
public:
	Vector2f();

	Vector2f(const float& x, const float& y);

	float Length() const { return hypotf(m_x, m_y); }


	Vector2f operator+(Vector2f& v2f) const;

	Vector2f operator-(Vector2f& v2f) const;


	void print();
	

	float getX() const { return m_x; }
	float getY() const { return m_y; }

	void setX(const float& x) { m_x = x; }
	void setY(const float& y) { m_y = y; }


private:

	float m_x;
	float m_y;

};