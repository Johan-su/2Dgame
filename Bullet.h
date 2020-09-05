#pragma once
#include <SDL.h>
#include "Entity.h"



class Bullet : public Entity
{
public:

	Bullet();
	Bullet(const float& x, const float& y, const float& rotation, const float& velocity);
	virtual void update();
	

private:
};


class Missile : public Bullet
{
public:
	Missile();
	void update() override;


private:
};

class Nuke : public Missile
{
public:
	Nuke();





private:
};