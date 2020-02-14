#pragma once
#include "SDL.h"
#include <iostream>
class Player {
public:
	Player();
private:
	float m_x;
	float m_y;
	float m_speedx;
	float m_speedy;
	~Player();
};