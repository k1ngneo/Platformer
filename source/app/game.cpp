#include "Platformer/app/game.h"

#include "Platformer/display/window.h"
#include "Platformer/logic/tile.h"

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include <iostream>
#include <fstream>

Window* Game::window = nullptr;
Renderer* Game::renderer = nullptr;
Camera Game::cam(0.0, 0.0, 0.0, 0.0);

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
	renderer->_camera = &cam;

	cam._win_w = &(window->w);
	cam._win_h = &(window->h);

	cam.setScale(3.0);
}

void Game::quit() {
	delete renderer;
	delete window;

	for (auto i = textures.begin(); i != textures.end(); ++i) {
		SDL_DestroyTexture(i->second->tex);
		delete i->second;
	}

	for (unsigned int i = 0; i < gameObjects.size(); ++i) {
		delete gameObjects[i];
	}
	gameObjects.clear();

	SDL_Quit();
	IMG_Quit();
}

void Game::load_level(const char* lvlname) {
	std::string fullLvlPath = std::string(SDL_GetBasePath()) + "worlds/" + lvlname;
	unsigned int world_width, world_height;

	load_texture("ludek.bmp");
	load_texture("ludek.png");
	load_texture("grass_tile.png");

	Sprite ludek, clouds;
	ludek.bindTexture("ludek.bmp");
	ludek.setPos({ 0.0, 0.0 });
	ludek.setDim({ 30.0, 20.0 });
	renderer->submit(&ludek);
	clouds.bindTexture("ludek.png");
	clouds.setPos({ -10.0, 0.0 });
	clouds.setDim({ 50.0, 30.0 });
	renderer->submit(&clouds);

	std::fstream fworld;
	fworld.open(fullLvlPath.c_str(), std::ios::in);
	if (fworld.is_open()) {
		fworld >> world_width >> world_height;

		Tile* newtile;
		int type = 0;
		for (unsigned int i = 0; i < world_height; ++i) {
			for (unsigned int j = 0; j < world_width; ++j) {
				fworld >> type;
				if (type == 0) {
					continue;
				}
				else {
					newtile = new Tile(j * 1.0, i * 1.0, (Tile::Type)type);
					renderer->submit(&(newtile->_sprite));
					gameObjects.push_back(newtile);
				}
			}
		}

		fworld.close();
	}
	else {
		std::cerr << "Failed to open a world file \"" << lvlname << "\"\n";
	}

	std::cout << "Number of game objects: " << gameObjects.size() << "\n";

	game_loop();
}

Texture* Game::getTexture(const char* name) {
	if (textures.count(name) != 0) {
		return textures[name];
	}
	else {
		return nullptr;
	}
}