#ifndef PLATFORMER_TILE_H
#define PLATFORMER_TILE_H

#include "Platformer/app/game.h"
#include "Platformer/display/sprite.h"
#include "Platformer/logic/game_object.h"

class Tile : GameObject {

public:
	enum class Type {
		NONE = 0, GRASS, DIRT, ROCK, ICE
	} tile_type;

private:
	Sprite _sprite;

public:
	Tile(const Vector2f& pos, Type tile_type);
	~Tile();

	inline const Vector2f& getPos() { return _sprite.getPos(); }
	inline const Vector2f& getDim() { return _sprite.getDim(); }

	friend void Game::load_level(const char* lvlname);
};

#endif // PLATFORMER_TILE_H