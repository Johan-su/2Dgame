#include "Texture.h"
#include "Game.h"

template<typename T>
static void print(T t)
{
	std::cout << t << std::endl;
}
Texture_list::Texture_list()
	: texture_array(), surface_texture_loader(nullptr)
{
	std::cout << "Texture list created" << std::endl;
}


void Texture_list::init()
{
	print(this);
	print("texture loading");
	SDL_Texture* texture_array[] =
	{
	load("resources/texture/bmp/effects/ship_explosion.bmp"),
	
	
	
	};
	//std::cout << sizeof(texture_array) << std::endl;
}
Texture_list* Texture_list::get_Texture()
{
	static Texture_list* instance = new Texture_list();
	return instance;
}

SDL_Texture* Texture_list::load(const char* path)
{
	surface_texture_loader = SDL_LoadBMP(path);
	if (surface_texture_loader != NULL)
	{
		std::cout << path << " Loaded successfully" << std::endl;
		auto texture = SDL_CreateTextureFromSurface(renderer, surface_texture_loader);
		SDL_FreeSurface(surface_texture_loader);
		return texture;

	}
	return nullptr;
}
