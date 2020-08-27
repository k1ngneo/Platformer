#include "Platformer/logic/player.h"

#include "Platformer/display/renderer.h"

Player::Player()
	: GameObject(Type::PLAYER)
{
	_sprite.setPos({ 0.0, 0.0 });
	_sprite.setDim({ 1.0, 1.0 });
}

Player::Player(const Vector2f& pos)
	: GameObject(Type::PLAYER)
{
	_sprite.setPos(pos);
	_sprite.setDim({ 1.0, 1.0 });
}

Player::~Player()
{}

void Player::moveLeft() {
	setPos(_sprite.getPos() - Vector2f(0.1f, 0.0f));
}

void Player::moveRight() {
	setPos(_sprite.getPos() + Vector2f(0.1f, 0.0f));
}


void Player::setPos(double x, double y) {
	_sprite.setPos(Vector2f(x, y));
}

void Player::setPos(const Vector2f& pos) {
	_sprite.setPos(pos);
}


void Player::bindToRenderer(Renderer* renderer) {
	renderer->submit(&_sprite);
}