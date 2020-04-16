#ifndef PLATFORMER_GAME_OBJECT_H
#define PLATFORMER_GAME_OBJECT_H

#include "Platformer/display/sprite.h"

class GameObject {

public:
	enum class Type {
		NONE = 0, TILE, PLAYER, NON_STATIC
	} gameObject_type;

private:
	double _x, _y;

public:
	GameObject();
	GameObject(double x, double y);
	~GameObject();

	void getPos(double& x, double& y);
	void setPos(double x, double y);
};

#endif // PLATFORMER_GAME_OBJECT_H