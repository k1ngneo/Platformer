#ifndef PLATFORMER_MAP_H
#define PLATFORMER_MAP_H

class Map {

public:
	unsigned int width, height;
	unsigned int** cells;

	Map(unsigned int width, unsigned int height);
	~Map();
};

#endif // PLATFORMER_MAP_H