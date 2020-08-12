#include "Platformer/app/fps_counter.h"

FPSCounter::FPSCounter()
	: _currentMeasurement(0),
	_currentTime(0), _lastMeasuredTime(0),
	_fps(0.0f)
{
	for (unsigned int i = 0; i < _MEASUREMENT_NUM; ++i) {
		_measurements[i] = 30.0f;
	}
}

FPSCounter::~FPSCounter()
{}

float FPSCounter::countFPS() {
	_lastMeasuredTime = _currentTime;
	_currentTime = SDL_GetPerformanceCounter();

	double deltaTime = (double)(_currentTime - _lastMeasuredTime) / (double)SDL_GetPerformanceFrequency();
	_measurements[_currentMeasurement] = 1.0 / deltaTime;
	_currentMeasurement = (_currentMeasurement + 1) % _MEASUREMENT_NUM;

	_fps = 0.0f;
	for (unsigned int i = 0; i < _MEASUREMENT_NUM; ++i) {
		_fps += _measurements[i];
	}

	_fps /= _MEASUREMENT_NUM;

	return _fps;
}

void FPSCounter::capFPS(unsigned int cap) {
	double diffrence = (2.0 / (double)cap) - (1.0 / _fps);
	diffrence *= 1000.0;
	if(diffrence > 0.0)
		SDL_Delay((Uint32)diffrence);
}