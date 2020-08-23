#pragma once
#include "SDL.h"
#include "Vector2f.h"

class Entity
{
public:

	Vector2f getPosition() const { return m_position; }
	Vector2f getSize() const { return m_size; }
	float getVelocity() const { return m_velocity; }
	float getRotation() const { return m_rotation; }

	bool isDead() const { return m_dead; }

	virtual void update() = 0;
	virtual void render() = 0;	
protected:
	Entity();




	Vector2f m_position;
	Vector2f m_size;

	float m_velocity;
	float m_rotation;

	bool m_dead;
	

	SDL_FRect m_render_box;
};