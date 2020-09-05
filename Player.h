#pragma once
#include "SDL.h"
#include "Entity.h"
#include "Vector2f.h"


class Player : public Entity
{
public:
	Player();

	Player(const float& x, const float& y, const float& rotation);

	Player(const Vector2f& vec_pos, const float& rotation);

	void damage(const float& f);
	void fire();

	void move_forward();
	void move_left();
	void move_backward();
	void move_right();

	void update() override;


	void lvlup();

	void set_ship(const int& ship);

public:

	bool m_forward;
	bool m_left;
	bool m_backward;
	bool m_right;
	bool m_firing;
	int count;

protected:
	uint8_t m_ship;

	uint8_t m_lvl;


	float m_maxHP;
	float m_HP;
	
};