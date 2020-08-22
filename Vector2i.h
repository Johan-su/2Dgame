#pragma once
#pragma once
#include <cmath>
class Vector2i
{
public:
	Vector2i();

	Vector2i(const int& x, const int& y);

	float Length() const { return hypotf((float)m_x, (float)m_y); }


	Vector2i operator+(Vector2i& v2i) const;

	Vector2i operator-(Vector2i& v2i) const;

	void print();


	int getX() const { return m_x; }
	int getY() const { return m_y; }

	void setX(const int& x) { m_x = x; }
	void setY(const int& y) { m_y = y; }


private:

	int m_x;
	int m_y;

};