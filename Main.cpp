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

Game *game = nullptr;

int main(int argc, char* argv[]) {

	game = new Game();
	game->init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 576, 0);

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
	return 0;
}