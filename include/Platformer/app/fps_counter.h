#ifndef PLATFORMER_FPS_COUNTER_H
#define PLATFORMER_FPS_COUNTER_H

#include <SDL2/SDL.h>

class FPSCounter {
	static const unsigned int _MEASUREMENT_NUM = 10;
	unsigned int _currentMeasurement;

	Uint64 _currentTime;
	Uint64 _lastMeasuredTime;
	float _measurements[_MEASUREMENT_NUM];
	float _fps;

public:
	FPSCounter();
	~FPSCounter();

	float countFPS();
	void capFPS(unsigned int cap);
	
	inline float getFPS() { return _fps; }
};

#endif // PLATFORMER_FPS_COUNTER_H