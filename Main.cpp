#include <iostream>
#include <memory>
#include <SDL.h>
#include <chrono>
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
	p.move_forward();

	//p.update();







	

	game = new Game();
	game->init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, 0);

	auto MS_PER_UPDATE = std::chrono::nanoseconds(16666666);


	auto previous = std::chrono::high_resolution_clock::now();
	std::chrono::nanoseconds lag(0);
	while (game->running()) {
		auto current = std::chrono::high_resolution_clock::now();
		auto elapsed = current - previous;
		previous = current;
		lag += elapsed;

		game->Events();

		while (lag >= MS_PER_UPDATE)
		{
		game->update();
			lag -= MS_PER_UPDATE;
		}

		game->render(); 
	}
	
	game->clean();

	delete game;
	std::cin;
	return 0;
}