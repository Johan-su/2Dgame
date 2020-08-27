#pragma once
#include <SDL.h>
#include "Entity.h"



class Bullet : Entity
{
public:

	Bullet();
	virtual void update();
	virtual void render();
	


private:
};


class Missile : Bullet
{
public:

	void update() override;
	void render() override;


private:
};

class Nuke : Missile
{

};