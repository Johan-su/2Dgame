#include <iostream>
#include <vector>
#include "Texture.h"
#include "Game.h"
template<typename T>
static void print(T t)
{
	std::cout << t << std::endl;
}

Texture_list::Texture_list()
	: texture_array(new std::vector<SDL_Texture*>), surface_texture_loader(nullptr)
{

}
void Texture_list::init()
{

	texture_array->push_back(load_img("resources/texture/bmp/test_tile.bmp"));
	texture_array->push_back(load_img("resources/texture/bmp/backgrounds/Space_background.bmp"));
	/*texture_array->push_back(load_img("resources/texture/bmp/test_tile.bmp"));
	texture_array->push_back(load_img("resources/texture/bmp/test_tile.bmp"));
	texture_array->push_back(load_img("resources/texture/bmp/test_tile.bmp"));
	texture_array->push_back(load_img("resources/texture/bmp/test_tile.bmp"));
	texture_array->push_back(load_img("resources/texture/bmp/test_tile.bmp"));
	texture_array->push_back(load_img("resources/texture/bmp/test_tile.bmp"));
	texture_array->push_back(load_img("resources/texture/bmp/test_tile.bmp"));
	texture_array->push_back(load_img("resources/texture/bmp/test_tile.bmp"));*/
}
SDL_Texture* Texture_list::get_texture(const unsigned int& element)
{
	if (element >= texture_array->size())
	{
		std::cout << "element out of bounds for list" << std::endl;
		return;
	}
	return texture_array->at(element);
}

Texture_list* Texture_list::get_Texture_list()
{
	static Texture_list* instance = new Texture_list();
	return instance;
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
