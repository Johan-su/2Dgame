#pragma once
#include "SDL.h"
#include "Entity.h"
#include "Vector2f.h"

//static const float PI = 3.1415926f;

class Player : Entity
{
public:
	Player();

	Player(const float& x, const float& y, const float& w, const float& h, const float& rotation);

	Player(const Vector2f& vec_pos, const Vector2f& vec_size, const float& rotation);

	void damage(const float& f);
	void fire();

	void move_forward();
	void move_left();
	void move_backward();
	void move_right();

	void update() override;
	void render() override;

	void move_update();
	void collision();

	void lvlup();


	bool m_forward;
	bool m_left;
	bool m_backward;
	bool m_right;

protected:

	uint8_t m_lvl;

	SDL_Rect m_srcrect;

	float m_maxHP;
	float m_HP;
	
	static SDL_Texture* texture;
};