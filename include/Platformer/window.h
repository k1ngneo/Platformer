#ifndef PLATFORMER_WINDOW_H
#define PLATFORMER_WINDOW_H

#include "SDL2/SDL.h"

class Window {
public:
	int w, h;
	const char* title;
	SDL_Window* win;
	
	Window(const char* title, int width, int height);
	~Window();
};

#endif // PLATFORMER_WINDOW_H