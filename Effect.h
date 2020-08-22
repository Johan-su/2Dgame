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
	static Effect* createEffect(const float& x, const float& y, const uint8_t& type);

	virtual void update() = 0;
	virtual void next_state() = 0;
	virtual void render() = 0;
protected:
	virtual ~Effect();
	float m_x, m_y;
	SDL_Rect src_rect;

};

class Explosion_ship : public Effect
{
public:
	Explosion_ship();
	Explosion_ship(const float& x, const float& y);

	void update();
	void next_state();
	void render();
protected:
	static const unsigned int TEXTURE_OFFSET = 8; // TODO: add offset
	static SDL_Texture* texture;
	SDL_FRect dest_rect;
};

class Hit_bullet : public Effect
{
public:
	Hit_bullet();
	Hit_bullet(const float& x, const float& y);

	void update();
	void next_state();
protected:
	static const uint16_t TEXTURE_OFFSET; // TODO: add offset
	static SDL_Texture* texture;
	SDL_FRect destrect;
};