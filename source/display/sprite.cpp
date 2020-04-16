#include "Platformer/display/sprite.h"
#include "Platformer/display/renderer.h"

#include "Platformer/app/game.h"

#include "SDL2/SDL_image.h"

#include <iostream>
#include <string>

Sprite::Sprite() {
	_texture = nullptr;
	_uv = { 0, 0, 0, 0 };
}

Sprite::~Sprite() {
}

void Sprite::bindTexture(const char* texture) {
	std::string path = std::string(SDL_GetBasePath()) + texture;
	_texture = Game::getTexture(texture);
	if (!_texture) {
		std::cerr << "Failed to bind a texture \"" << texture << "\" to a sprite!\n";
	}
	else {
		_uv = { 0, 0, (int)_texture->w, (int)_texture->h };
	}
}

void Sprite::setPos(const Vector2f& pos) {
	_pos = pos;
}
void Sprite::setDim(const Vector2f& dim) {
	_dim = dim;
}