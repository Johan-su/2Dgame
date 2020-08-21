#include <memory>
#include "Effect.h"


Effect::Effect()
{

}

Effect Effect::createEffect(const float& x, const float& y, const uint8_t& type)
{
	switch (type)
	{
	case (EFFECT_DUMMY):
		break;
	case (EFFECT_SHIP_EXPLOSION):
		//return new Explosion_ship(); // TODO: fix
		break;
	case (EFFECT_BULLET_HIT):
		break;











	default:
		break;
	}
}