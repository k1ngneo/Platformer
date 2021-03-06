#include "Platformer/app/game.h"

#include "Platformer/app/event_handler.h"
#include "Platformer/display/window.h"
#include "Platformer/logic/tile.h"

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include <iostream>
#include <fstream>

Window* Game::window = nullptr;
Renderer* Game::renderer = nullptr;
FPSCounter Game::fpsCounter;
Camera Game::cam(0.0, 0.0, 0.0, 0.0);

bool Game::running = true;

std::map<std::string, Texture*> Game::textures;
SpatialHash Game::gameObjects;

Player Game::player;

void Game::game_loop() {
	while (running)
	{
		fpsCounter.countFPS();
		fpsCounter.capFPS(60);

		EventHandler::pollEvents();

		if (EventHandler::isKeyPressed(KB_ESCAPE)) {
			Game::quit();
			exit(0);
		}

		if (EventHandler::isKeyPressed(KB_F2)) {
			Vector2i pos = EventHandler::getMousePosition();
			std::cout << pos.x << " " << pos.y << std::endl;
		}

		if (EventHandler::isKeyPressed(KB_A)) {
			player.moveLeft();
		}

		if (EventHandler::isKeyPressed(KB_D)) {
			player.moveRight();
		}

		//std::cout << "fps: " << fpsCounter.getFPS() << std::endl;

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

	EventHandler::init();

	window = new Window("Platformer", 900, 600);
	renderer = new Renderer(window);
	renderer->_camera = &cam;

	cam._win_w = &(window->_w);
	cam._win_h = &(window->_h);

	cam.setScale(3.0);
}

void Game::quit() {
	delete renderer;
	delete window;

	for (auto i = textures.begin(); i != textures.end(); ++i) {
		SDL_DestroyTexture(i->second->tex);
		delete i->second;
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
	load_texture("dirt_tile.png");
	load_texture("hero.png");

	player.bindTexture("hero.png");

	Sprite ludek, clouds;
	ludek.bindTexture("ludek.bmp");
	ludek.setPos({ 0.0, 0.0 });
	ludek.setDim({ 30.0, 20.0 });
	renderer->submit(&ludek);
	clouds.bindTexture("ludek.png");
	clouds.setPos({ -10.0, 0.0 });
	clouds.setDim({ 50.0, 30.0 });
	renderer->submit(&clouds);

	player.bindToRenderer(renderer);

	std::fstream fworld;
	fworld.open(fullLvlPath.c_str(), std::ios::in);
	if (fworld.is_open()) {
		fworld >> world_width >> world_height;
		
		float playerX, playerY;
		fworld >> playerX >> playerY;
		player.setPos(Vector2f(playerX, playerY));

		Tile* newtile;
		int type = 0;
		for (unsigned int i = 0; i < world_height; ++i) {
			for (unsigned int j = 0; j < world_width; ++j) {
				fworld >> type;
				if (type == 0) {
					continue;
				}
				else {
					newtile = new Tile(Vector2f(j * 1.0, i * 1.0), (Tile::Type)type);
					renderer->submit(&(newtile->_sprite));
					gameObjects.add(newtile);
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