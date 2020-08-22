#include <memory>
#include <iostream>
#include "Effect.h"

template<typename T>
static void print(T t)
{
	std::cout << t << std::endl;
}

Effect::Effect()
	:m_x(0), m_y(0), srcrect({ 0, 0, 0, 0 })
{
	print("effect default ctor");
}

std::unique_ptr<Effect> Effect::createEffect(const float& x, const float& y, const uint8_t& type)
{
	switch (type)
	{
	case (EFFECT_DUMMY):
		return nullptr;
		break;
	case (EFFECT_SHIP_EXPLOSION):
		return std::unique_ptr<Effect> (new Explosion_ship(x, y));
		break;
	case (EFFECT_BULLET_HIT):
		return std::unique_ptr<Effect>(new Hit_bullet(x, y));
		break;
	default:
		std::cout << "Unknown Effect type" << std::endl;
		return nullptr;
		break;
	}
}

Explosion_ship::Explosion_ship()
	: Explosion_ship::Explosion_ship(0.0f, 0.0f)
{
}

Explosion_ship::Explosion_ship(const float& x, const float& y)
{
	m_x = x;
	m_y = y;
	print("explosion ship ctor");
}




Hit_bullet::Hit_bullet(const float&  x, const float&  y)
{
	m_x = x;
	m_y = y;
	print("hit bullet ctor");
}
