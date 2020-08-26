#include <iostream>
#include "Entity.h"
#include "Player.h"
#include "Vector2f.h"
#include "Texture.h"
#include "Enemy.h"

template<typename T>
static void print(T t)
{
	std::cout << t << std::endl;
}

Entity::Entity()
	: m_dead(false), m_position(0.0f, 0.0f), m_size(0.0f, 0.0f), m_velocity(0.0f), m_rotation(0.0f), m_render_box({ 0.0f, 0.0f, 0.0f, 0.0f })
{
}
void Entity::init()
{
	Player::texture = Texture_list::get_Texture_list()->get_texture(2);
	Enemy::texture = Texture_list::get_Texture_list()->get_texture(2);
}