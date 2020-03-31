#include "Platformer/window.h"

Window::Window(const char* title, int width, int height)
	: w(width), h(height),
	title(title)
{
	win = SDL_CreateWindow(	title,
							SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
							w, h,
							SDL_WINDOW_RESIZABLE);

}

Window::~Window() {
	SDL_DestroyWindow(win);
	win = nullptr;
}