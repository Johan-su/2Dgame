#pragma once
#include "SDL.h"
#include <iostream>
#include "Player.h"

extern SDL_Event e;
extern SDL_Renderer* renderer;

class Game {
public:
	Game();
	//~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void Events();
	void update();
	void render();
	void clean();
	void load();

	void keyEvent(int keycode, bool press);

	

	bool running() { return Running; }


	Player* mainPlayer;

private:
	int cnt;
	bool Running;
	SDL_Window* window;
	SDL_Surface* surface_texture_loader;
	SDL_Texture* texture;
	SDL_FRect rect;
};