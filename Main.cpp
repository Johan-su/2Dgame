#include <iostream>
#include <SDL.h>
#include "Game.h"

Game *game = nullptr;

int main(int argc, char* argv[]) {
	game = new Game();
	game->init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, 0);
	while (game->running()) {
		game->HandleEvents();
		game->update();
		game->render();
	}
	
	game->clean();
	std::cin;
	return 0;
}