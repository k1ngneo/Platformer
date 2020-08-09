#ifndef PLATFORMER_GAME_OBJECT_H
#define PLATFORMER_GAME_OBJECT_H

#include "Platformer/display/sprite.h"
#include "Platformer/maths/vector.h"

class GameObject {

public:
	enum class Type {
		NONE = 0, TILE, PLAYER, NON_STATIC
	} gameObjectType;

private:
	Vector2f _pos;

public:
	GameObject(Type type = Type::NONE);
	GameObject(double x, double y, Type type = Type::NONE);
	GameObject(const Vector2f& pos, Type type = Type::NONE);
	~GameObject();

	inline Vector2f getPos() { return _pos; }
	void setPos(double x, double y);
	void setPos(const Vector2f& new_pos);
};

#endif // PLATFORMER_GAME_OBJECT_H