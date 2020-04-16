#ifndef PLATFORMER_WINDOW_H
#define PLATFORMER_WINDOW_H

#include "SDL2/SDL.h"

class Game;

class Window {
	int w, h;
	const char* title;
	SDL_Window* win;
	SDL_Surface* mainSurface;
	
public:
	Window(const char* title, int width, int height);
	~Window();

	inline SDL_Window* getWindow() { return win; }

	friend Game;
};

#endif // PLATFORMER_WINDOW_H