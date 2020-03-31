#include "Platformer/renderer.h"

Renderer::Renderer(SDL_Window* window)
	: window(window)
{
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(renderer);
}

void Renderer::submit(SDL_Texture* texture, const SDL_Rect& src, const SDL_Rect& dest) {
	Sprite* newSprite = new Sprite();
	newSprite->texture = texture;
	newSprite->src = src;
	newSprite->dest = dest;
	sprites.push_back(newSprite);
}

void Renderer::submit(Sprite* texture) {
	sprites.push_back(texture);
}

void Renderer::flush() {
	for (unsigned int i = 0; i < sprites.size(); ++i) {
		SDL_Texture* texture = sprites[i]->texture;
		SDL_RenderCopy(renderer, texture, &(sprites[i]->src), &(sprites[i]->dest));
	}

	SDL_RenderPresent(renderer);
}