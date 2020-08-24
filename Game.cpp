#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Texture.h"
#include "Entity.h"

template<typename T>
static void print(T t)
{
	std::cout << t << std::endl;
}
// tutorial http://lazyfoo.net/tutorials/SDL/index.php

SDL_Renderer* renderer = nullptr;
SDL_Event e;

Game::Game() 
{
	Running = false;

	window = nullptr;
	surface_texture_loader = nullptr;
	texture = nullptr;
	mainPlayer = nullptr;

	rect.w = 100.0f;
	rect.h = 100.0f;
	rect.x = 10.0f;
	rect.y = 10.0f;
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{

	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Systems initialized" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "window created" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer) {
			//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "renderer created" << std::endl;
			Texture_list::get_Texture()->init(); // real textures
			std::cout << "texture-list initalized" << std::endl;
			load(); // test textures
		}

		Running = true;
		add_effect(Vector2f({ 50.0f, 50.0f }), EFFECT_SHIP_EXPLOSION);
	} else {
		Running = false;
	}
}


void Game::Events()
{
	while (SDL_PollEvent(&e) != 0) 
	{
		switch (e.type)
		{
		case SDL_QUIT:
			Running = false;
			break;
		case SDL_KEYDOWN:
			keyEvent(e.key.keysym.sym, true);
			break;

		case SDL_KEYUP:
			keyEvent(e.key.keysym.sym, false);
			break;
		default:
			break;
		}
	}
}

void Game::update() 
{
	for (Effect* e : effect_list)
	{
		e->update();
	}
	for (Entity* e : entity_list)
	{
		e->update();
	}
}
void Game::render() 
{
	SDL_RenderClear(renderer);

	SDL_RenderCopyF(renderer, texture, NULL, NULL);

	SDL_RenderPresent(renderer);

	for (Effect* e : effect_list)
	{
		e->render();
	}
	for (Entity* e : entity_list)
	{
		e->render();
	}


}
void Game::clean()
{
	mainPlayer = nullptr;
	surface_texture_loader = nullptr;

	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);

	SDL_DestroyRenderer(renderer);

	SDL_Quit();
	std::cout << "game cleaned" << std::endl;
}
void Game::load() //TODO: change/remove temptest
{
	auto t = Texture_list::get_Texture();
	auto bt = *t;
	texture = bt.texture_array[0];
	/*surface_texture_loader = SDL_LoadBMP("resources/texture/bmp/test_tile.bmp");
	if (surface_texture_loader != NULL)
	{
		std::cout << "TEMP texture loaded" << std::endl;
		texture = SDL_CreateTextureFromSurface(renderer, surface_texture_loader);
		if (renderer != nullptr)
		{
			print("renderer worked in game");
		}
		SDL_FreeSurface(surface_texture_loader);
		
	}*/
	/*texture = Texture_list::get_Texture()->m_t;
	if (texture == (Texture_list::get_Texture()->m_t))
	{
		std::cout << "texture equality" << std::endl;
	}*/
	
}
void Game::keyEvent(int keycode, bool press)
{
	switch (keycode)
	{
	case SDLK_w:
		if (press) 
		{
			mainPlayer->m_forward = true;
			break;
		}
		mainPlayer->m_forward = false;
		break;
	case SDLK_a:
		if (press)
		{
			mainPlayer->m_left = true;
			break;
		}
		mainPlayer->m_left = false;
		break;
	case SDLK_s:
		if (press)
		{
			mainPlayer->m_backward = false;
			break;
		}
		mainPlayer->m_backward = false;
		break;
	case SDLK_d:
		if (press)
		{
			mainPlayer->m_right = true;
			break;
		}
		mainPlayer->m_right = false;
		break;
	case SDLK_LSHIFT:
		if (press)
		{
			break;
		}
		break;
	case SDLK_F7:
		if (press)
		{
			add_effect(mainPlayer->getPosition(), EFFECT_SHIP_EXPLOSION);
			break;
		}
		break;

	default:
		break;
	}
}

void Game::add_effect(const Vector2f& vec_pos, const uint8_t& type)
{
	effect_list.push_back(Effect::create_effect(vec_pos, type));
}