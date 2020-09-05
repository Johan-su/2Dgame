#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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
	texture = nullptr;
	mainPlayer = nullptr;

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
			std::cout << "renderer created" << std::endl;
			//SDL_RenderSetLogicalSize(renderer, 16, 9);
			//std::cout << "renderer scaled" << std::endl;
			load(); // test textures

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
	for (int i = 0; i < 2; ++i)
	{
	add_effect(Vector2f({ (float)(rand() % (102*6)),(float)(rand() % (57*6)) }), EFFECT_EXPLOSION);
	}
	//add_effect(Vector2f({40.0f, 40.0f}), EFFECT_SHIP_EXPLOSION);

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


	for (Effect* e : effect_list)
	{
		e->render();
	}
	for (Entity* e : entity_list)
	{
		e->render();
	}

	SDL_RenderPresent(renderer);

}
void Game::clean()
{
	Texture_list::get_Texture_list()->clean();

	mainPlayer = nullptr;
	for (int i = 0; i < effect_list.size(); ++i)
	{
		Effect* e = effect_list.at(i);
		delete e;
		effect_list.clear();
	}

	for (int i = 0; i < entity_list.size(); ++i)
	{
		Entity* e = entity_list.at(i);
		delete e;
		entity_list.clear();
	}

	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);

	SDL_DestroyRenderer(renderer);

	SDL_Quit();
	std::cout << "game cleaned" << std::endl;
}
void Game::load()
{
	Texture_list::get_Texture_list()->init();
	std::cout << "texture-list initalized" << std::endl;

	texture = Texture_list::get_Texture_list()->get_texture(1);
	std::cout << "background loaded" << std::endl;

	mainPlayer = new Player();
	mainPlayer->set_ship(9);
	entity_list.push_back(mainPlayer);
}
void Game::keyEvent(int keycode, bool press)
{
	switch (keycode)
	{
	case SDLK_ESCAPE:
		Running = false;
		break;
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
			mainPlayer->m_backward = true;
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
	case SDLK_r:
		if (press)
		{
			add_effect(mainPlayer->getPosition(), EFFECT_EXPLOSION);
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

void Game::clear_dead_effects()
{
	for (int i = 0; i < effect_list.size(); ++i)
	{
		Effect* e = effect_list.at(i);
		if (e->m_dead)
		{
			delete e;
			effect_list.erase(effect_list.begin() + i);
		}
	}
}
void Game::clear_dead_entities()
{
	for (int i = 0; i < entity_list.size(); ++i)
	{
		Entity* e = entity_list.at(i);
		if (e->m_dead)
		{
			delete e;
			entity_list.erase(entity_list.begin() + i);
		}
	}
}