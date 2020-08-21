#pragma once
#include <SDL.h>
enum Effect_types
{
	EFFECT_DUMMY,
	EFFECT_SHIP_EXPLOSION,
	EFFECT_BULLET_HIT,

};

class Effect
{
public:
	Effect();
	Effect static createEffect(const float& x, const float& y, const uint8_t& type);

protected:
	float m_x, m_y;
	SDL_Rect srcrect;

};

class Explosion_ship : public Effect
{
public:
	Explosion_ship();
protected:
	static const uint16_t TEXTURE_OFFSET; // TODO: add offset
	static SDL_Texture* texture;
	static SDL_FRect destrect;
};

class Hit_bullet : public Effect
{
public:
	Hit_bullet();
protected:
	static const uint16_t TEXTURE_OFFSET; // TODO: add offset
	static SDL_Texture* texture;
	static SDL_FRect destrect;
};