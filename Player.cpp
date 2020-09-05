#pragma once
#include <cmath>
#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Vector2f.h"
#include "Texture.h"

template<typename T>
static void print(T t)
{
	std::cout << t << std::endl;
}


Player::Player()
	: Player(0.0f, 0.0f, 0.0f)
{
}

Player::Player(const float& x, const float& y, const float& rotation)
	: Player(Vector2f(x, y), rotation)
{
}

Player::Player(const Vector2f& vec_pos, const float& rotation)
	: count(0), m_forward(false), m_left(false), m_backward(false), m_right(false), m_ship(0), m_lvl(0), m_maxHP(100.0f), m_HP(m_maxHP)
{
	m_srcrect = { 0, 0, 256, 256 };
	m_position = vec_pos;
	m_size = Vector2f({ 40.0f, 40.0f });
	m_rotation = rotation;
	texture = Texture_list::get_Texture_list()->get_texture(2);

	m_render_box = { m_position.getX(), m_position.getY(), m_size.getX(), m_size.getY() };

}

void Player::damage(const float& x)
{
	
	m_HP -= x;

	if (m_HP < 0)
	{
		m_dead = true;
		return;
	}
	if (m_HP > m_maxHP)
	{
		m_HP = m_maxHP;
	}
}

void Player::fire()
{
	m_velocity;
}

void Player::move_forward()
{
	m_velocity += 0.05f;
}

void Player::move_left()
{
	m_rotation-= 0.06981317007f; // PI/45
}

void Player::move_backward()
{
	m_velocity -= 0.02f;
}

void Player::move_right()
{
	m_rotation += 0.06981317007f; // PI/45
}

void Player::update()
{
	if (count == 60)
	{
		print(m_rotation);
		m_size.print();
		m_position.print();
		count = 0;
	}
	++count;
	if (m_firing)
	{
		fire();
	}
	if (m_forward)
	{
		move_forward();
	}
	else if(m_backward)
	{
		move_backward();
	}
	if (m_left)
	{
		move_left();
	}
	else if (m_right)
	{
		move_right();
	}
	move_update();
	m_velocity *= 0.98f; // friction
	collision();

}

void Player::lvlup()
{
	if (m_lvl < 4) // m_lvl 0 is the first level.
	{
		++m_lvl;
	}
}

void Player::set_ship(const int& ship)
{
	if (ship > 9)
	{
		m_srcrect = { 0, 2560 + 384 * (ship - 10), 256, 384 };
		return;
	}
	m_srcrect = { 0, ship * 256, 256, 256 };
}

