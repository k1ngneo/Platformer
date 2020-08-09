#ifndef PLATFORMER_PLAYER_H
#define PLATFORMER_PLAYER_H

#include "Platformer/logic/game_object.h"
#include "Platformer/display/sprite.h"

class Player : GameObject {

	Sprite _sprite;

public:
	Player();
	Player(const Vector2f& pos);
	~Player();
};

#endif // PLATFORMER_PLAYER_H