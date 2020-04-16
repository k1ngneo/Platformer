
#include "Platformer/app/game.h"
#include "Platformer/display/window.h"
#include "Platformer/display/renderer.h"
#include "Platformer/display/sprite.h"

#include "Platformer/maths/vector.h"

#include <iostream>

int main(int argc, const char * argv[])
{
	Game::init();
	Game::load_level("world1.txt");

	Game::quit();

	return 0;
}