#pragma once
#include <SDL.h>
#include <vector>
class Audio
{
public:

	std::vector<SDL_AudioSpec*>* audio_list;



public:
	void init();
	void clean();
	static Audio* get_Audio();
	SDL_AudioStream* get_AudioStream();

private:
	SDL_AudioSpec* load_sound(const char* path);
	Audio();
};