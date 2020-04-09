#include "Platformer/display/window.h"

#include "iostream"

Window::Window(const char* title, int width, int height)
	: w(width), h(height),
	title(title),
	mainSurface(nullptr)
{
	win = SDL_CreateWindow(	title,
							SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
							w, h,
							SDL_WINDOW_RESIZABLE);

	if (win != nullptr) {
		mainSurface = SDL_GetWindowSurface(win);
	}
	else {
		std::cerr << "Failed to create a game window!\n";
	}
}

Window::~Window() {
	SDL_DestroyWindow(win);
	win = nullptr;
}