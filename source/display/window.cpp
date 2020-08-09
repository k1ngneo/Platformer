#include "Platformer/display/window.h"

#include "iostream"

Window::Window(const char* title, int width, int height)
	: _w(width), _h(height),
	_title(title),
	_mainSurface(nullptr)
{
	_win = SDL_CreateWindow(	title,
							SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
							_w, _h,
							SDL_WINDOW_RESIZABLE);

	if (_win != nullptr) {
		_mainSurface = SDL_GetWindowSurface(_win);
	}
	else {
		std::cerr << "Failed to create a game window!\n";
	}
}

Window::~Window() {
	SDL_DestroyWindow(_win);
	_win = nullptr;
}

void Window::resize(int width, int height) {
	_w = width;
	_h = height;

	
}