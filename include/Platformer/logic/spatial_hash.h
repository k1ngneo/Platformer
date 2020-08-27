#ifndef PLATFORMER_SPATIAL_HASH_H
#define PLATFORMER_SPATIAL_HASH_H

#include <unordered_map>
#include <forward_list>

#include "Platformer/logic/game_object.h"
#include "Platformer/maths/vector.h"

class SpatialHash {
	class List {
		std::forward_list<GameObject*> list;
		unsigned int size;

	public:
		List();
		~List();

		void push_front(GameObject* obj);
		void erase(GameObject* obj);
	};

	std::unordered_map<unsigned long int, List> hash;
	unsigned int cellsize;
	unsigned int objNum;

public:
	SpatialHash();
	~SpatialHash();

	void add(GameObject* obj);
	void remove(GameObject* obj);
	void clear();

	inline unsigned int size() { return objNum; }
};

#endif // PLATFORMER_SPATIAL_HASH_H