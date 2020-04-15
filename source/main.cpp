
#include "Platformer/app/game.h"
#include "Platformer/display/window.h"
#include "Platformer/display/renderer.h"
#include "Platformer/display/sprite.h"

#include "SDL2/SDL.h"
#include "SDL2/SDl_image.h"

#ifdef __cplusplus
extern "C"
#endif

int main(int argc, const char * argv[])
{
	Game::init();
	Game::load_level("thelevel");

	Game::quit();

	return 0;
}