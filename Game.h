#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "SDL.h"
#include "Player.h"
#include "Effect.h"

extern SDL_Event e;
extern SDL_Renderer* renderer;

class Game {
public:
	Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);


	void Events();
	void update();
	void render();
	void clean();
	void load();

	void keyEvent(int keycode, bool press);

	void add_effect(const Vector2f& vec_pos, const uint8_t& type);

	void clear_dead_effects();
	void clear_dead_entities();

	bool running() { return Running; }


	Player* mainPlayer;

	std::vector<Entity*> entity_list;
	std::vector<Effect*> effect_list;



private:
	bool Running;
	SDL_Window* window;
	SDL_Texture* texture;
};