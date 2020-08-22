#include <iostream>
#include "Entity.h"
#include "Vector2f.h"

template<typename T>
static void print(T t)
{
	std::cout << t << std::endl;
}

Entity::Entity()
	: m_position(0.0f, 0.0f), m_size(0.0f, 0.0f), m_velocity(0.0f), m_rotation(0.0f), m_dead(false), m_render_box({ 0.0f, 0.0f, 0.0f, 0.0f })
{
}