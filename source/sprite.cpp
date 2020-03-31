#include "Platformer/sprite.h"
#include "Platformer/renderer.h"

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

	SDL_Surface* loadingSurface = SDL_LoadBMP(fullpath.c_str());
	if (!loadingSurface) {
		fprintf(stderr, "Failed to open BMP file '%s'\n", path);
		return;
	}

	src = { 0, 0, loadingSurface->w, loadingSurface->h };
	dest = { 0, 0, loadingSurface->w, loadingSurface->h };

	texture = SDL_CreateTextureFromSurface(renderer->renderer, loadingSurface);
	SDL_FreeSurface(loadingSurface);
}