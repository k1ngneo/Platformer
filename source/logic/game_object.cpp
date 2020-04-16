#include "Platformer/logic/game_object.h"

GameObject::GameObject()
	: _x(0.0), _y(0.0)
{}

GameObject::GameObject(double x, double y)
	: _x(x), _y(y)
{}

GameObject::~GameObject()
{}

void GameObject::getPos(double& x, double& y) {
	x = _x;
	y = _y;
}

void GameObject::setPos(double x, double y) {
	_x = x;
	_y = y;
}