#include "Platformer/display/renderer.h"

Renderer::Renderer(Window* window)
	: _window(window), _camera(nullptr)
{
	_renderer = SDL_CreateRenderer(window->win, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0xff);
	_camera = new Camera(-1.0, -1.0, 2.0, 2.0);
}

Renderer::~Renderer()
{
	delete _camera;
	SDL_DestroyRenderer(_renderer);
}

void Renderer::submit(Sprite* sprite) {
	_sprites.push_back(sprite);
}

void Renderer::flush() {
	SDL_RenderClear(_renderer);

	for (unsigned int i = 0; i < _sprites.size(); ++i) {
		// camera handling here I suppose
		SDL_RenderCopy(_renderer, _sprites[i]->_texture->tex, &(_sprites[i]->_src), &(_sprites[i]->_dest));
	}

	SDL_RenderPresent(_renderer);
}