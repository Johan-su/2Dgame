#pragma once
#include <SDL.h>



class Bullet
{
public:

	Bullet();
	virtual void update() = 0;
	virtual void render() = 0;
	


private:
};