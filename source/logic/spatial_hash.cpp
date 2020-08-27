#include "Platformer/logic/spatial_hash.h"

#include <iostream>

SpatialHash::List::List() : size(0) {}
SpatialHash::List::~List() {
	for (auto it = list.begin(); it != list.end(); ++it) {
		delete (*it);
	}
	list.erase_after(list.before_begin(), list.end());
}

void SpatialHash::List::push_front(GameObject* obj) {
	list.push_front(obj);
	size += 1;
}

void SpatialHash::List::erase(GameObject* obj) {
	list.remove(obj);
}


SpatialHash::SpatialHash() : cellsize(2), objNum(0) {}
SpatialHash::~SpatialHash() {
	clear();
}

void SpatialHash::add(GameObject* obj) {
	Vector2f pos_f = obj->getPos();
	Vector2f dim_f = obj->getDim();
	Vector2i pos_i, dim_i;

	pos_i.x = ((int)(pos_f.x / (double)cellsize)) * (int)cellsize;
	pos_i.y = ((int)(pos_f.y / (double)cellsize)) * (int)cellsize;

	dim_i.x = ((int)(dim_f.x / (double)cellsize)) * (int)cellsize;
	dim_i.y = ((int)(dim_f.y / (double)cellsize)) * (int)cellsize;

	unsigned long int key;

	for (int i = pos_i.x; i <= pos_i.x + dim_i.x; ++i) {
		for (int j = pos_i.y; j <= pos_i.y + dim_i.y; ++j) {
			key = ((i + j) * (i + j + 1) >> 1) + j;

			if (!hash.count(key)) {
				hash.emplace(key, SpatialHash::List::List());
			}
			
			hash[key].push_front(obj);
		}
	}

	objNum += 1;
}

void SpatialHash::remove(GameObject* obj) {
	Vector2f pos_f = obj->getPos();
	Vector2f dim_f = obj->getDim();
	Vector2i pos_i, dim_i;

	pos_i.x = ((int)(pos_f.x / (double)cellsize)) * (int)cellsize;
	pos_i.y = ((int)(pos_f.y / (double)cellsize)) * (int)cellsize;

	dim_i.x = ((int)(dim_f.x / (double)cellsize)) * (int)cellsize;
	dim_i.y = ((int)(dim_f.y / (double)cellsize)) * (int)cellsize;

	unsigned long int key;

	for (int i = pos_i.x; i <= pos_i.x + dim_i.x; ++i) {
		for (int j = pos_i.y; i <= pos_i.y + dim_i.y; ++j) {
			key = ((i + j) * (i + j + 1) >> 1) + j;
			hash[key].erase(obj);
		}
	}

	objNum -= 1;
}

void SpatialHash::clear() {
	hash.clear();
	objNum = 0;
}