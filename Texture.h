#pragma once
#include <SDL.h>
class Texture_list
{
public:









	SDL_Texture* texture_array;


	SDL_Texture* m_t;
	static Texture_list* get_Texture();
private:
	SDL_Texture* load_img(const char* path);
	Texture_list();

	SDL_Surface* surface_texture_loader;
};