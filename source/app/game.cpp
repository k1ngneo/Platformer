#include "Platformer/app/game.h"

#include "Platformer/display/window.h"

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include <iostream>

Window* Game::window = nullptr;
Renderer* Game::renderer = nullptr;

std::map<std::string, Texture*> Game::textures;
std::vector<GameObject*> Game::gameObjects;

void Game::game_loop() {
	SDL_Event evnt;
	bool running = true;
	while (running)
	{
		SDL_PollEvent(&evnt);

		if (evnt.type == SDL_QUIT)
		{
			running = false;
		}

		renderer->flush();
	}
}

void Game::load_texture(const char* texture_name) {
	std::string path = std::string(SDL_GetBasePath()) + std::string("textures/") + texture_name;
	if (textures.count(texture_name) == 0) {
		Texture* new_texture = nullptr;

		SDL_Surface* sur = nullptr;
		sur = IMG_Load(path.c_str());
		if (!sur) {
			fprintf(stderr, "Failed to open image \"%s\"\n", path.c_str());
			return;
		}
		else {
			SDL_SetColorKey(sur, SDL_TRUE, SDL_MapRGBA(sur->format, 0, 0, 0, 0xff));
			new_texture = new Texture();
			new_texture->tex = SDL_CreateTextureFromSurface(renderer->_renderer, sur);
			new_texture->w = (unsigned)sur->w;
			new_texture->h = (unsigned)sur->h;
			SDL_FreeSurface(sur);
			if (new_texture->tex != nullptr) {
				SDL_SetTextureBlendMode(new_texture->tex, SDL_BLENDMODE_BLEND);
				textures.insert(std::pair<const char*, Texture*>(texture_name, new_texture));
			}
		}
	}
}

void Game::init() {
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

	window = new Window("Platformer", 900, 600);
	renderer = new Renderer(window);
}

void Game::quit() {
	delete renderer;
	delete window;

	for (auto i = textures.begin(); i != textures.end(); ++i) {
		SDL_DestroyTexture(i->second->tex);
		delete i->second;
	}

	for (auto i = gameObjects.begin(); i != gameObjects.end(); ++i) {
		delete (*i);
		gameObjects.erase(i);
	}

	SDL_Quit();
	IMG_Quit();
}

void Game::load_level(const char* lvlname) {
	load_texture("ludek.bmp");
	load_texture("ludek.png");

	Sprite* sp1 = new Sprite();
	Sprite* sp2 = new Sprite();
	sp1->bindTexture("ludek.bmp");
	sp2->bindTexture("ludek.png");

	sp1->_dest = sp1->_src = {0, 0, (int)sp1->_texture->w, (int)sp1->_texture->h};
	sp2->_dest = sp2->_src = {0, 0, (int)sp2->_texture->w, (int)sp2->_texture->h};
	
	renderer->submit(sp1);
	renderer->submit(sp2);

	game_loop();

	delete sp1, sp2;
}

Texture* Game::getTexture(const char* name) {
	if (textures.count(name) != 0) {
		return textures[name];
	}
	else {
		return nullptr;
	}
}