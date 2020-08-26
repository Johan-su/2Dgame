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

	static void init();

	static void clean();
	virtual void update() = 0;
	virtual void next_state() = 0;
	virtual void render() = 0;
	bool m_dead;
protected:
	uint8_t count;
	Vector2f m_pos;
	SDL_Rect src_rect;

};

class Explosion : public Effect
{
public:
	Explosion();
	Explosion(const Vector2f& vec_pos);

	void update() override;
	void next_state() override;
	void render() override;
	static SDL_Texture* texture;
protected:
	unsigned int count;
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
	static SDL_Texture* texture;
protected:
	static const uint16_t TEXTURE_OFFSET; // TODO: add offset
	SDL_FRect dest_rect;
};