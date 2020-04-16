#include "Platformer/logic/tile.h"

Tile::Tile(double x, double y, Type tile_type)
	: GameObject(x, y), tile_type(tile_type)
{
	_sprite.setPos({ x, y });
	_sprite.setDim({ 1.0, 1.0 });

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