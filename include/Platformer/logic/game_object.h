#ifndef PLATFORMER_GAME_OBJECT_H
#define PLATFORMER_GAME_OBJECT_H

#include "Platformer/display/sprite.h"
#include "Platformer/maths/vector.h"

class GameObject {

public:
	enum class Type {
		NONE = 0, TILE, PLAYER, NON_STATIC
	} gameObjectType;

	
	GameObject(Type type = Type::NONE);
	~GameObject();

	virtual const Vector2f& getPos() = 0;
	virtual const Vector2f& getDim() = 0;
};

#endif // PLATFORMER_GAME_OBJECT_H