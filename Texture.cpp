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

}
void Texture_list::init()
{

	SDL_Texture* texture_array[100]; //TODO: change to correct array size
	texture_array[0] = load_img("resources/texture/bmp/test_tile.bmp");

	//m_t = load_img("resources/texture/bmp/test_tile.bmp");
	if (texture_array[0] == nullptr)
	{
	std::cout << "texture_array[0] == nullptr" << std::endl;
	}
}
Texture_list* Texture_list::get_Texture()
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
		if (renderer == nullptr)
		{
			print("renderer failed");
			return nullptr;
		}
		if (texture == nullptr)
		{
			print("texture failed");
			return nullptr;
		}
		SDL_FreeSurface(surface_texture_loader);
		std::cout << path << " loaded" << std::endl;
		return texture;

	}
	std::cout << path << " failed to load" << std::endl;
	return nullptr;
}