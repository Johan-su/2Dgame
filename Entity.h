#pragma once
#include "SDL.h"
#include "Vector2f.h"

class Entity
{
public:
	Entity();


	Vector2f getPosition() const { return m_position; }
	Vector2f getSize() const { return m_size; }
	float getVelocity() const { return m_velocity; }
	float getRotation() const { return m_rotation; }

	bool isDead() const { return m_dead; }

	virtual void update() = 0;
	virtual void render() = 0;	
	bool m_dead;

	static void init();
protected:




	Vector2f m_position;
	Vector2f m_size;

	float m_velocity;
	float m_rotation;

	

	SDL_FRect m_render_box;
};