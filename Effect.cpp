#include <memory>
#include <iostream>
#include "Effect.h"
#include "Texture.h"
#include "Game.h"

template<typename T>
static void print(T t)
{
	std::cout << t << std::endl;
}

Effect::Effect()
	:m_x(0), m_y(0), src_rect({ 0, 0, 0, 0 })
{
	print("effect default ctor");
}
Effect::~Effect()
{
	//TODO: add removal of, pointer to effect
}

Effect* Effect::createEffect(const float& x, const float& y, const uint8_t& type)
{
	switch (type)
	{
	case (EFFECT_DUMMY):
		return nullptr;
		break;
	case (EFFECT_SHIP_EXPLOSION):
		return new Explosion_ship(x, y);
		break;
	case (EFFECT_BULLET_HIT):
		return new Hit_bullet(x, y);
		break;
	default:
		throw "Unknown Effect type";
		return nullptr;
		break;
	}
}
//----------------------------------------------------------------------------Explosion_ship
Explosion_ship::Explosion_ship()
	: Explosion_ship::Explosion_ship(0.0f, 0.0f)
{
}

Explosion_ship::Explosion_ship(const float& x, const float& y)
	: dest_rect({ x, y, 4.0f, 4.0f }) //TODO: determine real size of ship
{
	src_rect = { 0, 0, 96, 12 };
	m_x = x;
	m_y = y;
	texture = Texture_list::get_Texture()->texture_array[0];
	print("explosion ship ctor");
}
void Explosion_ship::update()
{
	print("expl update");
	next_state();
}

void Explosion_ship::next_state()
{
	int& first_src_rect_val = *(int*)(&src_rect);
	first_src_rect_val += 96;
	print((*(int*)(&src_rect)));
	if (first_src_rect_val >= 1152)
	{
		delete this;
	}
}

void Explosion_ship::render()
{
	SDL_RenderCopyF(renderer, texture, &src_rect, &dest_rect);
}
SDL_Texture* Explosion_ship::texture = ; // TODO: fix problem look in texture.cpp/h


//----------------------------------------------------------------------------Explosion_ship end
Hit_bullet::Hit_bullet()
	: Hit_bullet::Hit_bullet(0.0f, 0.0f)
{
}

Hit_bullet::Hit_bullet(const float& x, const float& y)
	: destrect({x, y, 4.0f, 4.0f}) //TODO: determine real size of bullet
{
	m_x = x;
	m_y = y;
	print("hit bullet ctor");
}

void Hit_bullet::update()
{
	print("hit bull update");

}
void Hit_bullet::next_state()
{

}

