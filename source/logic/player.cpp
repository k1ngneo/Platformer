#include "Platformer/logic/player.h"

Player::Player()
	: GameObject(Type::PLAYER)
{
	_sprite.setPos({ 0.0, 0.0 });
	_sprite.setDim({ 1.0, 2.0 });
}

Player::Player(const Vector2f& pos)
	: GameObject(pos, Type::PLAYER)
{
	_sprite.setPos(pos);
	_sprite.setDim({ 1.0, 2.0 });
}

Player::~Player()
{}