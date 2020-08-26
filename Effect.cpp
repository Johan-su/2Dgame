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
	: m_dead(false), count(0), m_pos({ 0.0f, 0.0f }), src_rect({ 0, 0, 0, 0 })
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

void Effect::init()
{
	Explosion::texture = Texture_list::get_Texture_list()->get_texture(4);
	Hit_bullet::texture = Texture_list::get_Texture_list()->get_texture(0); //TODO: change to correct texture
}

void Effect::clean()
{
	
	SDL_DestroyTexture(Explosion::texture);
	SDL_DestroyTexture(Hit_bullet::texture);
}

//----------------------------------------------------------------------------Explosion_ship
SDL_Texture* Explosion::texture;
Explosion::Explosion()
	: Explosion::Explosion(Vector2f{ 0.0f, 0.0f })
{
}

Explosion::Explosion(const Vector2f& vec_pos)
	: count(0), dest_rect({ vec_pos.getX(), vec_pos.getY(), 160.0f, 160.0f }) // TODO: determine real size of ship change 4.0f, 4.0f
{
	src_rect = { 0, 0, 96, 96 };

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
	int& first_src_rect_val = *(int*)(&src_rect);
	first_src_rect_val += 96;
	if (first_src_rect_val >= 1152)
	{

		m_dead = true;
		game->clear_dead_effects();
	}
}

void Explosion::render()
{
	SDL_RenderCopyF(renderer, texture, &src_rect, &dest_rect);
}


//----------------------------------------------------------------------------Explosion_ship end
SDL_Texture* Hit_bullet::texture;
Hit_bullet::Hit_bullet()
	: Hit_bullet::Hit_bullet(Vector2f{ 0.0f, 0.0f })
{
}

Hit_bullet::Hit_bullet(const Vector2f& vec_pos)
	: dest_rect({ vec_pos.getX(), vec_pos.getY(), 4.0f, 4.0f}) //TODO: determine real size of bullet hit
{
	print("hit bullet ctor");
}

void Hit_bullet::update()
{
	print("hit bull update");

}
void Hit_bullet::next_state()
{

}
void Hit_bullet::render()
{
	SDL_RenderCopyF(renderer, texture, &src_rect, &dest_rect);
}


