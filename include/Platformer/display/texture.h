#ifndef PLATFORMER_TEXTURE_H
#define PLATFORMER_TEXTURE_H

#include "SDL2/SDL.h"

class Texture {
public:
	SDL_Texture* tex;
	unsigned int w, h;
};

#endif // PLATFORMER_TEXTURE_H