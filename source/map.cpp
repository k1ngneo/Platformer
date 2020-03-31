#include "Platformer/map.h"

Map::Map(unsigned int width, unsigned int height)
	: width(width), height(height)
{
	cells = new unsigned int * [width];
	for (int i = 0; i < width; ++i) {
		cells[i] = new unsigned int[height];
		cells[i] = 0;
	}
}

Map::~Map()
{
	for (int i = 0; i < width; ++i) {
		delete[] cells[i];
	}
	delete cells;
}