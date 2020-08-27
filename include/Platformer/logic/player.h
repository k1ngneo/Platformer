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

	void moveLeft();
	void moveRight();

	void setPos(double x, double y);
	void setPos(const Vector2f& pos);

	void bindToRenderer(Renderer* renderer);

	inline void bindTexture(const char* texture) { _sprite.bindTexture(texture); }

	inline const Sprite& getSprite() { return _sprite; }
	inline const Vector2f& getPos() { return _sprite.getPos(); }
	inline const Vector2f& getDim() { return _sprite.getDim(); }
};

#endif // PLATFORMER_PLAYER_H