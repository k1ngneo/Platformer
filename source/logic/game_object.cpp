#include "Platformer/logic/game_object.h"

GameObject::GameObject(Type type)
	: gameObjectType(type), _pos({0.0, 0.0})
{}

GameObject::GameObject(double x, double y, Type type)
	: gameObjectType(type), _pos({x, y})
{}

GameObject::GameObject(const Vector2f& pos, Type type)
	: gameObjectType(type), _pos(pos)
{}

GameObject::~GameObject()
{}

void GameObject::setPos(double x, double y) {
	_pos = { x, y };
}

void GameObject::setPos(const Vector2f& new_pos) {
	_pos = new_pos;
}