#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#ifdef __cplusplus
extern "C"
#endif

#include "Platformer/display/window.h"
#include "Platformer/display/renderer.h"
#include "Platformer/display/camera.h"
#include "Platformer/display/texture.h"

#include "Platformer/logic/game_object.h"

#include <string>
#include <vector>
#include <map>

class Game {
	static Window* window;
	static Renderer* renderer;
	static Camera cam;

	static std::map<std::string, Texture*> textures;
	static std::vector<GameObject*> gameObjects;

private:
	static void game_loop();

	static void load_texture(const char* texture_name);

public:
	static void init();
	static void quit();

	static void load_level(const char* lvlname);

	static inline Window* getWindow() { return window; }
	static Texture* getTexture(const char* name);
};

#endif // PLATFORMER_GAME_H