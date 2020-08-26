#pragma once
#include <SDL.h>
#include <vector>
class Texture_list
{
public:











	std::vector<SDL_Texture*>* texture_array;



	void init();
	SDL_Texture* get_texture(const unsigned int& element);
	static Texture_list* get_Texture_list();
	void clean();
private:
	SDL_Texture* load_img(const char* path);
	Texture_list();


	SDL_Surface* surface_texture_loader;
};