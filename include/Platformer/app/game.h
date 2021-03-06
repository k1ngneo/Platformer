#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

//#ifdef __cplusplus
//extern "C"
//#endif

#include "Platformer/app/event_handler.h"
#include "Platformer/app/fps_counter.h"

#include "Platformer/display/window.h"
#include "Platformer/display/renderer.h"
#include "Platformer/display/camera.h"
#include "Platformer/display/texture.h"

#include "Platformer/logic/game_object.h"
#include "Platformer/logic/player.h"
#include "Platformer/logic/spatial_hash.h"

#include <string>
#include <vector>
#include <map>

class Game {
	static Window* window;
	static Renderer* renderer;
	static FPSCounter fpsCounter;
	static Camera cam;

	static std::map<std::string, Texture*> textures;
	//static std::vector<GameObject*> gameObjects;
	static SpatialHash gameObjects;

	static Player player;

	static bool running;

private:
	static void game_loop();

	static void load_texture(const char* texture_name);

public:
	static void init();
	static void quit();

	static void load_level(const char* lvlname);

	static inline Window* getWindow() { return window; }
	static Texture* getTexture(const char* name);

	friend void EventHandler::pollEvents();
};

#endif // PLATFORMER_GAME_H