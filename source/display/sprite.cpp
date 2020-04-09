#include "Platformer/display/sprite.h"
#include "Platformer/display/renderer.h"

#include "SDL2/SDL_image.h"

#include <string>

Sprite::Sprite() {
	texture = nullptr;
	src = { 0, 0, 0, 0 };
	dest = { 0, 0, 0, 0 };
}

Sprite::~Sprite() {
	SDL_DestroyTexture(texture);
}

void Sprite::load(const char* path, Renderer* renderer) {
	std::string fullpath = std::string(SDL_GetBasePath()) + path;
	
	SDL_Surface* sur = nullptr;

	sur = IMG_Load(fullpath.c_str());
	if (!sur) {
		fprintf(stderr, "Failed to open image '%s'\n", path);
		return;
	}
	else {
		src = { 0, 0, sur->w, sur->h };
		dest = { 0, 0, sur->w, sur->h };
		SDL_SetColorKey(sur, SDL_TRUE, SDL_MapRGBA(sur->format, 0, 0, 0, 0xff));
	}

	texture = SDL_CreateTextureFromSurface(renderer->renderer, sur);
	SDL_FreeSurface(sur);
	if (texture != nullptr) {
		SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
	}
}