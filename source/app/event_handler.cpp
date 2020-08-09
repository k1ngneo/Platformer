#include "Platformer/app/event_handler.h"

#include "Platformer/app/game.h"

#include <SDL2/SDL.h>

#define PLATFORMER_KEYCODE_OFFSET (1073741881 - 127)
#define PLATFORMER_KEYCODE_TABLE_SIZE 353

class Game;

SDL_Event EventHandler::evnt;

const unsigned int EventHandler::KB_KEY_COUNT = PLATFORMER_KEYCODE_TABLE_SIZE;
bool EventHandler::kb_keys[KB_KEY_COUNT];
//std::function<void(void)> EventHandler::kb_handlers[EventHandler::KB_KEY_COUNT];

const unsigned int EventHandler::MOUSE_BUTTONS_COUNT = 6;
bool EventHandler::mouse_buttons[MOUSE_BUTTONS_COUNT];
//std::function<void(void)> EventHandler::ms_handlers[EventHandler::MOUSE_BUTTONS_COUNT];

Vector2i EventHandler::m_pos;

void EventHandler::init() {
	for (unsigned int i = 0; i < KB_KEY_COUNT; ++i) {
		kb_keys[i] = false;
	}
	for (unsigned int i = 0; i < MOUSE_BUTTONS_COUNT; ++i) {
		mouse_buttons[i] = false;
	}
}

void EventHandler::pollEvents() {
	SDL_PollEvent(&evnt);

	switch (evnt.type) {
		case SDL_QUIT:
		{
			Game::running = false;
		} break;
		case SDL_WINDOWEVENT:
		{
			switch (evnt.window.event) {
				case SDL_WINDOWEVENT_RESIZED:
				{
					//window->resize(evnt.window.data1, evnt.window.data2);
					fprintf(stderr, "Resized: %d, %d\n", evnt.window.data1, evnt.window.data2);
				} break;
			}
		} break;
		case SDL_KEYDOWN:
		{
			unsigned int elem = evnt.key.keysym.sym;

			if (elem > 127)
				elem = elem - PLATFORMER_KEYCODE_OFFSET;
			
			kb_keys[elem] = true;
		} break;
		case SDL_KEYUP:
		{
			unsigned int elem = evnt.key.keysym.sym;

			if (elem > 127)
				elem = elem - PLATFORMER_KEYCODE_OFFSET;

			kb_keys[elem] = false;
		} break;
		case SDL_MOUSEBUTTONDOWN:
		{
			mouse_buttons[evnt.button.button] = true;
		} break;
		case SDL_MOUSEBUTTONUP:
		{
			mouse_buttons[evnt.button.button] = false;
		} break;
		case SDL_MOUSEMOTION:
		{
			m_pos = Vector2i(evnt.motion.x, evnt.motion.y);
		}
	}
}

bool EventHandler::isKeyPressed(SDL_Keycode key) {
	unsigned int elem = (unsigned int)key;
	if (elem > 127) {
		elem = elem - PLATFORMER_KEYCODE_OFFSET;
	}
	
	return kb_keys[elem];
}