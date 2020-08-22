#include <iostream>
#include <memory>
#include <SDL.h>
#include "Game.h"
#include "Vector2f.h"
#include "Effect.h"

template<typename T>
static void print(T t)
{
	std::cout << t << std::endl;
}

class rr
{
	int x;
public:
	int getX()
	{
		return x;
	}

};

//Player p;
Game *game = nullptr;

int main(int argc, char* argv[]) {
	/*Vector2f vec = Vector2f(1.5f, 2.5f);
	vec.print();
	Vector2f vec1 = Vector2f(4.0f, 5.0f);
	vec1.print();

	Vector2f vec2 = vec + vec1;
	vec2.print();
	
	auto vec3 = vec2 - vec1;
	vec3.print();*/
	Player p(1.1f, 2.2f, 3.3f, 4.4f, 5.5f);
	auto e = Effect::createEffect(10.0f, 10.0f, EFFECT_SHIP_EXPLOSION);
	p.move_forward();
	e->update();

	//p.update();







	

	game = new Game();
	game->init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, 0);
	while (game->running()) {
		game->Events();
		game->update();
		game->render();
	}
	
	game->clean();

	delete game;
	std::cin;
	return 0;
}