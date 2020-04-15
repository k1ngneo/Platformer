#ifndef PLATFORMER_GAME_OBJECT_H
#define PLATFORMER_GAME_OBJECT_H

#include "Platformer/display/sprite.h"

class GameObject {
	Sprite* sprite;
	double x, y, w, h;
};

#endif // PLATFORMER_GAME_OBJECT_H