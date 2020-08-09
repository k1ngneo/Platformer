#ifndef PLATFORMER_EVENT_HANDLER_H
#define PLATFORMER_EVENT_HANDLER_H

#include "Platformer/app/event_defines.h"
#include "Platformer/maths/vector.h"

#include <SDL2/SDL.h>

#include <functional>

class EventHandler {

	static SDL_Event evnt;

	static const unsigned int KB_KEY_COUNT;
	static bool kb_keys[];
	//static std::function<void(void)> kb_handlers[];

	static const unsigned int MOUSE_BUTTONS_COUNT;
	static bool mouse_buttons[];
	//static std::function<void(void)> ms_handlers[];

	static Vector2i m_pos;

public:
	static void init();
	static void pollEvents();
	//static void addHandler(std::function<void(void)> func, SDL_Keycode key, bool onRelease = true);
	//static void addHandler(std::function<void(void)> func, SDL_MouseButtonEvent key, bool onRelease = true);
	//static void addHandler(std::function<void(void)> func, Event evnt_type);

	static bool isKeyPressed(SDL_Keycode type);
	static inline Vector2i getMousePosition() { return m_pos; }
};

#endif // PLATFORMER_EVENT_HANDLER_H