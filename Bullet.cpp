#include "Bullet.h"
#include "Game.h"

Bullet::Bullet()
	: Bullet(0.0f, 0.0f, 0.0f, 1.0f)
{

}
Bullet::Bullet(const float& x, const float& y, const float& rotation, const float& velocity)
	: m_srcrect({ 0, 0, 0, 0 })
{

}
SDL_Texture* Bullet::texture;

void Bullet::update()
{
	move_update();
	collision();
}
/*void Bullet::move_update()
{
	if (abs(m_rotation) >= 6.28318530718f) m_rotation = 0.0f; // 2x pi  = 0

	m_position = Vector2f(cos(m_rotation) * m_velocity, sin(m_rotation) * m_velocity) + m_position;
	m_render_box = { m_position.getX(), m_position.getY(), m_size.getX(), m_size.getY() };
}
void Bullet::collision()
{

}*/
void Bullet::render()
{
	SDL_RenderCopyExF(renderer, texture, &m_srcrect, &m_render_box, (m_rotation * 57.2957795131) + 90, NULL, SDL_FLIP_NONE);
}




//void Missile::