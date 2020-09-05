#include <memory>
#include <iostream>
#include "Effect.h"
#include "Texture.h"
#include "Game.h"
#include "Main.h"

template<typename T>
static void print(T t)
{
	std::cout << t << std::endl;
}

Effect::Effect()
	: m_dead(false), count(0), m_pos({ 0.0f, 0.0f }), m_srcrect({ 0, 0, 0, 0 })
{
}
Effect::~Effect()
{
}

Effect* Effect::create_effect(const Vector2f& vec_pos, const uint8_t& type)
{
	switch (type)
	{
	case (EFFECT_EXPLOSION):
		return new Explosion(vec_pos);
		break;
	case (EFFECT_BULLET_HIT):
		return new Hit_bullet(vec_pos);
		break;
	default:
		throw "Unknown Effect type";
		return nullptr;
		break;
	}
}


void Effect::render()
{
	SDL_RenderCopyF(renderer, m_texture, &m_srcrect, &m_destrect);

}

//----------------------------------------------------------------------------Explosion_ship
Explosion::Explosion()
	: Explosion::Explosion(Vector2f{ 0.0f, 0.0f })
{
}

Explosion::Explosion(const Vector2f& vec_pos)
	: count(0) // TODO: determine real size of ship change 4.0f, 4.0f
{
	m_destrect = { vec_pos.getX(), vec_pos.getY(), 160.0f, 160.0f };
	m_texture = Texture_list::get_Texture_list()->get_texture(4);
	m_srcrect = { 0, 0, 96, 96 };

}
void Explosion::update()
{
	++count;

	if (count == 3)
	{
		next_state();
		count = 0;
	}
}

void Explosion::next_state()
{
	int& first_m_srcrect_val = *(int*)(&m_srcrect);
	first_m_srcrect_val += 96;
	if (first_m_srcrect_val >= 1152)
	{

		m_dead = true;
		game->clear_dead_effects();
	}
}

//----------------------------------------------------------------------------Explosion_ship end
Hit_bullet::Hit_bullet()
	: Hit_bullet::Hit_bullet(Vector2f{ 0.0f, 0.0f })
{
}

Hit_bullet::Hit_bullet(const Vector2f& vec_pos)
{
	m_destrect = { vec_pos.getX(), vec_pos.getY(), 4.0f, 4.0f };
	m_texture = Texture_list::get_Texture_list()->get_texture(0);
	print("hit bullet ctor");
}

void Hit_bullet::update()
{
	print("hit bull update");

}
void Hit_bullet::next_state()
{

}


