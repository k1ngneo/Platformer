#include "SDL2/SDL.h"

#include "Platformer/window.h"
#include "Platformer/renderer.h"
#include "Platformer/sprite.h"

#ifdef __cplusplus
extern "C"
#endif

int main(int argc, const char * argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	Window* window = new Window("Platformer", 900, 600);
	Renderer* renderer = new Renderer(window->win);

	Sprite* sprite = new Sprite();
	sprite->load("ludek.bmp", renderer);
	renderer->submit(sprite);

	printf("%s\n", SDL_GetBasePath());

	SDL_Event evnt;
	bool running = true;
	while (running)
	{
		SDL_PollEvent(&evnt);

		if (evnt.type == SDL_QUIT)
		{
			running = false;
		}

		renderer->flush();
	}

	delete window;
	delete renderer;
	delete sprite;
	SDL_Quit();

	return 0;
}