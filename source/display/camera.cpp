#include "Platformer/display/camera.h"

#include "Platformer/display/window.h"
#include "Platformer/display/sprite.h"

#include "SDL2/SDL.h"

Camera::Camera(double x, double y, double w, double h)
	: _x(x), _y(y), _w(w), _h(h),
	_bx1(0.0), _by1(0.0), _bx2(w), _by2(h),
	_win_w(nullptr), _win_h(nullptr)
{
}

void Camera::setPosition(double x, double y) {
	_x = x;
	_y = y;
}

void Camera::setScale(double sc) {
	_scale = sc;
	_w = sc * 10.0;
	_h = _w * ((double)(*_win_h) / (double)(*_win_w));
}

void Camera::setBorders(double x1, double y1, double x2, double y2) {
	_bx1 = x1;
	_by1 = y1;
	_bx2 = x2;
	_by2 = y2;
}

void Camera::getTranPos(Sprite& sp, SDL_Rect& dest) {
	Vector2f obj = sp.getPos();
	Vector2f dim = sp.getDim();

	dest.x = (int)((obj.x - _x) / _w * (double)(*_win_w));
	dest.y = (int)((obj.y - _y) / _h * (double)(*_win_h));
	dest.w = (int)(dim.x / _w * (double)(*_win_w));
	dest.h = (int)(dim.y / _h * (double)(*_win_h));
}