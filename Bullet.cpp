#include "Bullet.h"
#include "Game.h"

Bullet::Bullet()
	: Bullet(0.0f, 0.0f, 0.0f, 1.0f)
{

}
Bullet::Bullet(const float& x, const float& y, const float& rotation, const float& velocity)
{
	//texture = ; TODO: add bullet texture
}

void Bullet::update()
{
	move_update();
	collision();
}




Missile::Missile()
{

}
void Missile::update()
{
	move_update();
	collision();
}

Nuke::Nuke()
{

}