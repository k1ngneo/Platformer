#ifndef PLATFORMER_SPRITE_H
#define PLATFORMER_SPRITE_H

#include "Platformer/display/texture.h"

#include "SDL2/SDL.h"

class Renderer;

class Sprite {
public:
	Texture* _texture;
	SDL_Rect _src, _dest;

	Sprite();
	~Sprite();

	void bindTexture(const char* texture);
};

#endif // PLATFORMER_SPRITE_H