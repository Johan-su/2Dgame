#include <iostream>
#include <vector>
#include <SDL.h>
#include "Texture.h"
#include "Game.h"
template<typename T>
static void print(T t)
{
	std::cout << t << std::endl;
}

enum Textures
{
	TEST_TILE,
	SPACE_BACKGROUND,
	SHIP_SHEET,
	BULLET_SHEET
};


Texture_list::Texture_list()
	: texture_array(nullptr), surface_texture_loader(nullptr)
{

}
void Texture_list::init()
{
	texture_array = new std::vector<SDL_Texture*>;
	texture_array->push_back(load_img("resources/texture/bmp/test_tile.bmp")); // 0
	texture_array->push_back(load_img("resources/texture/bmp/backgrounds/Space_background.bmp")); // 1
	texture_array->push_back(load_img("resources/texture/bmp/space_ships/ships_sheet.bmp")); // 2
	texture_array->push_back(load_img("resources/texture/bmp/projectiles/bullets_sheet.bmp")); // 3
	texture_array->push_back(load_img("resources/texture/bmp/effects/ship_explosion.bmp")); // 4
	//texture_array->push_back(load_img("resources/texture/bmp/test_tile.bmp"));
	//texture_array->push_back(load_img("resources/texture/bmp/test_tile.bmp"));
	//texture_array->push_back(load_img("resources/texture/bmp/test_tile.bmp"));
	//texture_array->push_back(load_img("resources/texture/bmp/test_tile.bmp"));
	//texture_array->push_back(load_img("resources/texture/bmp/test_tile.bmp"));
}
SDL_Texture* Texture_list::get_texture(const unsigned int& element)
{
	if (element >= texture_array->size())
	{
		throw "element out of bounds for list";
	}
	return texture_array->at(element);
}

Texture_list* Texture_list::get_Texture_list()
{
	static Texture_list* instance = new Texture_list();
	return instance;
}

void Texture_list::clean()
{
	for (int i = 0; i < texture_array->size(); ++i)
	{
		SDL_DestroyTexture(get_texture(i));
	}
	texture_array->clear();
	texture_array->~vector();
	texture_array = nullptr;
}

SDL_Texture* Texture_list::load_img(const char* path)
{
	surface_texture_loader = SDL_LoadBMP(path);
	if (surface_texture_loader != NULL)
	{
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface_texture_loader);
		if (texture == nullptr)
		{
			print("texture failed");
			return nullptr;
		}
		SDL_FreeSurface(surface_texture_loader);
		std::cout << path << " loaded" << std::endl;
		return texture;

	}
	std::cout << path << " failed to load, path maybe wrong?" << std::endl;
	return nullptr;
}
