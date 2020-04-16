#ifndef PLATFORMER_CAMERA_H
#define PLATFORMER_CAMERA_H

class Game;
class Sprite;
struct SDL_Rect;

class Camera {
	// current position
	double _x, _y, _w, _h;
	double _scale;

	// world borders
	double _bx1, _by1, _bx2, _by2;

	// window dimentions
	int *_win_w, *_win_h;

public:
	Camera(double x, double y, double w, double h);

	void setPosition(double x, double y);
	void setScale(double sc);
	void setBorders(double x1, double y1, double x2, double y2);

	void getTranPos(Sprite& sp, SDL_Rect& dest);

	friend Game;
};

#endif // PLATFORMER_CAMERA_H