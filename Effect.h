#pragma once
#include <SDL.h>
#include "Vector2f.h"
enum Effect_types
{
	EFFECT_EXPLOSION,
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
	void render();
	bool m_dead;
protected:
	uint8_t count;
	Vector2f m_pos;
	SDL_FRect m_destrect;
	SDL_Rect m_srcrect;
	SDL_Texture* m_texture;

};

class Explosion : public Effect
{
public:
	Explosion();
	Explosion(const Vector2f& vec_pos);

	void update() override;
	void next_state() override;
protected:
	unsigned int count;
};

class Hit_bullet : public Effect
{
public:
	Hit_bullet();
	Hit_bullet(const Vector2f& vec_pos);

	void update() override;
	void next_state() override;
protected:
};