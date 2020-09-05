#pragma once
#include <SDL.h>
#include "Entity.h"



class Bullet : public Entity
{
public:

	Bullet();
	Bullet(const float& x, const float& y, const float& rotation, const float& velocity);
	virtual void update();
	virtual void render();
	
	static SDL_Texture* texture;

private:
	SDL_Rect m_srcrect;
};


class Missile : public Bullet
{
public:

	void update() override;
	void render();
	static SDL_Texture* texture;


private:
	SDL_Rect m_srcrect;
};

class Nuke : public Missile
{
public:





private:
	SDL_Rect m_srcrect;
};