#include <iostream>
#include "Entity.h"
#include "Player.h"
#include "Vector2f.h"
#include "Texture.h"
#include "Enemy.h"
#include "Game.h"

template<typename T>
static void print(T t)
{
	std::cout << t << std::endl;
}

Entity::Entity()
	: m_dead(false), m_srcrect({0, 0, 0, 0}), m_position(0.0f, 0.0f), m_size(0.0f, 0.0f), m_velocity(0.0f), m_rotation(0.0f), m_render_box({ 0.0f, 0.0f, 0.0f, 0.0f })
{
}
void Entity::move_update()
{
	if (abs(m_rotation) >= 6.28318530718f) m_rotation = 0.0f; // 2x pi  = 0

	m_position = Vector2f(cos(m_rotation) * m_velocity, sin(m_rotation) * m_velocity) + m_position;
	m_render_box = { m_position.getX(), m_position.getY(), m_size.getX(), m_size.getY() };

}
void Entity::collision()
{

}
void Entity::render()
{
	SDL_RenderCopyExF(renderer, texture, &m_srcrect, &m_render_box, (m_rotation * 57.2957795131) + 90, NULL, SDL_FLIP_NONE);
}
void Entity::init()
{
	//Player::texture = Texture_list::get_Texture_list()->get_texture(2);
	//Enemy::texture = Texture_list::get_Texture_list()->get_texture(2);
}