#ifndef PLATFORMER_TEXTURE_H
#define PLATFORMER_TEXTURE_H

#include "SDL2/SDL.h"

class Renderer;

class Sprite {
public:
	SDL_Texture* texture;
	SDL_Rect src, dest;

	Sprite();
	~Sprite();

	void load(const char* path, Renderer* renderer);
};

#endif // PLATFORMER_TEXTURE_H