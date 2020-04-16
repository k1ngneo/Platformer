#ifndef PLATFORMER_SPRITE_H
#define PLATFORMER_SPRITE_H

#include "Platformer/display/texture.h"
#include "Platformer/maths/vector.h"

#include "SDL2/SDL.h"

class Renderer;

class Sprite {
	Texture* _texture;
	SDL_Rect _uv;
	
	Vector2f _pos;
	Vector2f _dim;

public:
	Sprite();
	~Sprite();

	void bindTexture(const char* texture);

	void setPos(const Vector2f& pos);
	void setDim(const Vector2f& dim);

	inline const Vector2f& getPos() { return _pos; }
	inline const Vector2f& getDim() { return _dim; }
	inline const SDL_Rect& getUV() { return _uv; }
	inline SDL_Texture* getSDL_Texture() { return _texture->tex; }
};

#endif // PLATFORMER_SPRITE_H