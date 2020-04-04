#ifndef PLATFORMER_RENDERER_H
#define PLATFORMER_RENDERER_H

#include "Platformer/window.h"

#include "SDL2/SDL.h"
#include "Platformer/sprite.h"

#include <vector>

class Renderer {
public:
	SDL_Renderer* renderer;
	Window* window;

private:
	std::vector<Sprite*> sprites;

public:
	Renderer(Window* window);
	~Renderer();

	void submit(SDL_Texture* texture, const SDL_Rect& src, const SDL_Rect& dest);
	void submit(Sprite* texture);
	void flush();
};

#endif // PLATFORMER_RENDERER_H