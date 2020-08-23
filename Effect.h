#pragma once
#include <SDL.h>
#include "Vector2f.h"
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
	~Effect();
	static Effect* create_effect(const Vector2f& vec_pos, const uint8_t& type);

	virtual void update() = 0;
	virtual void next_state() = 0;
	virtual void render() = 0;
protected:
	uint8_t count;
	Vector2f m_pos;
	SDL_Rect src_rect;

};

class Explosion_ship : public Effect
{
public:
	Explosion_ship();
	Explosion_ship(const Vector2f& vec_pos);

	void update() override;
	void next_state() override;
	void render() override;
protected:
	//static SDL_Texture* texture;
	SDL_FRect dest_rect;
};

class Hit_bullet : public Effect
{
public:
	Hit_bullet();
	Hit_bullet(const Vector2f& vec_pos);

	void update() override;
	void next_state() override;
	void render() override;
protected:
	static const uint16_t TEXTURE_OFFSET; // TODO: add offset
	static SDL_Texture* texture;
	SDL_FRect dest_rect;
};