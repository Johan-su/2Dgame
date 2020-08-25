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
	: count(0), m_pos({0.0f, 0.0f}), src_rect({ 0, 0, 0, 0 })
{
	//print("effect default ctor");
}
Effect::~Effect()
{
	//TODO: add removal of, pointer to effect or something else.
}

Effect* Effect::create_effect(const Vector2f& vec_pos, const uint8_t& type)
{
	switch (type)
	{
	case (EFFECT_DUMMY):
		return nullptr;
		break;
	case (EFFECT_SHIP_EXPLOSION):
		return new Explosion_ship(vec_pos);
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
//----------------------------------------------------------------------------Explosion_ship
Explosion_ship::Explosion_ship()
	: Explosion_ship::Explosion_ship(Vector2f{ 0.0f, 0.0f })
{
}

Explosion_ship::Explosion_ship(const Vector2f& vec_pos)
	: dest_rect({ vec_pos.getX(), vec_pos.getY(), 4.0f, 4.0f }) // TODO: determine real size of ship change 4.0f, 4.0f
{
	count = 0;
	src_rect = { 0, 0, 96, 12 };

	print("explosion ship ctor");
}
void Explosion_ship::update()
{
	//print("expl update");
	if (count == 1200)
	{
	//next_state();
	count = 0;
	}
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
	if (SDL_RenderCopyF(renderer, NULL, &src_rect, &dest_rect) == -1)
	{
		//std::cout << "expship render failed" << std::endl;
	}
}


//----------------------------------------------------------------------------Explosion_ship end
Hit_bullet::Hit_bullet()
	: Hit_bullet::Hit_bullet(Vector2f{ 0.0f, 0.0f })
{
}

Hit_bullet::Hit_bullet(const Vector2f& vec_pos)
	: dest_rect({ vec_pos.getX(), vec_pos.getY(), 4.0f, 4.0f}) //TODO: determine real size of bullet hit
{
	count = 0;
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
SDL_Texture* Hit_bullet::texture;// = Texture_list::get_Texture_list()->get_texture(0); //TODO:changed hit_bullet texture ,add offset to correct texture in list


