#include "SDL2/SDL.h"

#ifdef __cplusplus
extern "C"
#endif

int main(int argc, const char * argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("The Platformer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 600, SDL_WINDOW_RESIZABLE);

	SDL_Event evnt;
	bool running = true;
	while (running)
	{
		SDL_PollEvent(&evnt);

		if (evnt.type == SDL_QUIT)
		{
			running = false;
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}