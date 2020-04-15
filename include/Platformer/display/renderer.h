#ifndef PLATFORMER_RENDERER_H
#define PLATFORMER_RENDERER_H

#include "Platformer/display/window.h"
#include "Platformer/display/sprite.h"
#include "Platformer/display/camera.h"

#include "SDL2/SDL.h"

#include <vector>

class Renderer {
	SDL_Renderer* _renderer;
	Window* _window;
	Camera* _camera;

	std::vector<Sprite*> _sprites;

public:
	Renderer(Window* window);
	~Renderer();

	void submit(Sprite* sprite);
	void flush();

	friend class Game;
};

#endif // PLATFORMER_RENDERER_H