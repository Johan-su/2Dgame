#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Texture.h"

// tutorial http://lazyfoo.net/tutorials/SDL/index.php

SDL_Renderer* renderer = nullptr;
SDL_Event e;

Game::Game() 
{
	cnt = 0;
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

/*Game::~Game() 
{

}*/

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
			load(); // test textures
			Texture_list::get_Texture()->init(); // real textures
		}

		Running = true;
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
	//cnt++;
	//std::cout << "counter :" << cnt << std::endl;
}
void Game::render() 
{
	SDL_RenderClear(renderer);

	if (SDL_RenderCopyF(renderer, texture, NULL, &rect) == -1)
	{
		std::cout << "rendercopy failing" << std::endl;
	}

	SDL_RenderPresent(renderer);
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
	surface_texture_loader = SDL_LoadBMP("resources/texture/bmp/test_tile.bmp");
	if (surface_texture_loader != NULL)
	{
		std::cout << "TEMP texture loaded" << std::endl;
		texture = SDL_CreateTextureFromSurface(renderer, surface_texture_loader);
		SDL_FreeSurface(surface_texture_loader);
		
	}
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

	default:
		break;
	}
}