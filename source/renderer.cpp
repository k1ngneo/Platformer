#include "Platformer/renderer.h"

Renderer::Renderer(Window* window)
	: window(window)
{
	renderer = SDL_CreateRenderer(window->win, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xff);
	//SDL_BlendMode(SDL_BLENDMODE_BLEND);
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
	SDL_RenderClear(renderer);

	for (unsigned int i = 0; i < sprites.size(); ++i) {
		SDL_Texture* texture = sprites[i]->texture;
		SDL_RenderCopy(renderer, texture, &(sprites[i]->src), &(sprites[i]->dest));
	}

	SDL_RenderPresent(renderer);
}