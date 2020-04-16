#include "Platformer/display/renderer.h"

Renderer::Renderer(Window* window)
	: _window(window), _camera(nullptr)
{
	_renderer = SDL_CreateRenderer(window->getWindow(), -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0xff);
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(_renderer);
}

void Renderer::submit(Sprite* sprite) {
	_sprites.push_back(sprite);
}

void Renderer::flush() {
	SDL_RenderClear(_renderer);

	SDL_Rect dest;
	for (unsigned int i = 0; i < _sprites.size(); ++i) {
		_camera->getTranPos((*_sprites[i]), dest);
		SDL_RenderCopy(_renderer, _sprites[i]->getSDL_Texture(), &(_sprites[i]->getUV()), &dest);
	}

	SDL_RenderPresent(_renderer);
}