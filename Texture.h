#pragma once
#include <SDL.h>
class Texture_list
{
public:

	void init();








	SDL_Texture* texture_array;



	static Texture_list* get_Texture();
private:
	SDL_Texture* load(const char* path);
	Texture_list();

	SDL_Surface* surface_texture_loader;
};