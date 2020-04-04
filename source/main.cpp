
#include "Platformer/window.h"
#include "Platformer/renderer.h"
#include "Platformer/sprite.h"

#include "SDL2/SDL.h"
#include "SDL2/SDl_image.h"

#ifdef __cplusplus
extern "C"
#endif

int main(int argc, const char * argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

	Window* window = new Window("Platformer", 900, 600);
	Renderer* renderer = new Renderer(window);

	Sprite* fog = new Sprite();
	Sprite* bob = new Sprite();
	fog->load("ludek.png", renderer);
	bob->load("ludek.bmp", renderer);
	renderer->submit(bob);
	renderer->submit(fog);

	//sprite->dest = { 0, 0, window->w, window->h };

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
	delete fog;
	delete bob;
	SDL_Quit();

	return 0;
}