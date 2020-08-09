#ifndef PLATFORMER_WINDOW_H
#define PLATFORMER_WINDOW_H

#include "SDL2/SDL.h"

class Game;

class Window {
	int _w, _h;
	const char* _title;
	SDL_Window* _win;
	SDL_Surface* _mainSurface;
	
public:
	Window(const char* title, int width, int height);
	~Window();

	void resize(int width, int height);

	inline SDL_Window* getWindow() { return _win; }

	friend Game;
};

#endif // PLATFORMER_WINDOW_H