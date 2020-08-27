#include "Platformer/logic/tile.h"

Tile::Tile(const Vector2f& pos, Type tile_type)
	: GameObject(GameObject::Type::TILE), tile_type(tile_type)
{
	_sprite.setPos(pos);
	_sprite.setDim(Vector2f( 1.0, 1.0 ));

	switch (tile_type) {
		case Tile::Type::GRASS:
		{
			_sprite.bindTexture("grass_tile.png");
		} break;
		case Tile::Type::DIRT:
		{
			_sprite.bindTexture("dirt_tile.png");
		} break;
		default:
		{}
	}
}

Tile::~Tile() {
}