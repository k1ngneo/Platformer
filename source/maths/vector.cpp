#include "Platformer/maths/vector.h"

Vector2f::Vector2f()
	: x(0.0), y(0.0)
{}

Vector2f::Vector2f(double x, double y)
	: x(x), y(y)
{}

Vector2f::~Vector2f()
{}

Vector2f& Vector2f::operator=(const Vector2f& v) {
	this->x = v.x;
	this->y = v.y;
	return (*this);
}
Vector2f operator+(const Vector2f& v1, const Vector2f& v2) {
	Vector2f result;
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	return result;
}
Vector2f operator-(const Vector2f& v1, const Vector2f& v2) {
	Vector2f result;
	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	return result;
}
Vector2f operator*(const Vector2f& v, double a) {
	Vector2f result;
	result.x = v.x * a;
	result.y = v.y * a;
	return result;
}
Vector2f operator*(double a, const Vector2f& v) {
	Vector2f result;
	result.x = v.x * a;
	result.y = v.y * a;
	return result;
}
Vector2f operator*(const Vector2f& v1, const Vector2f& v2) {
	Vector2f result;
	result.x = v1.x * v2.x;
	result.y = v1.y * v2.y;
	return result;
}


const Vector2f& operator+=(Vector2f& v1, const Vector2f& v2) {
	v1.x += v2.x;
	v1.y += v2.y;
	return v1;
}
const Vector2f& operator-=(Vector2f& v1, const Vector2f& v2) {
	v1.x -= v2.x;
	v1.y -= v2.y;
	return v1;
}
const Vector2f& operator*=(Vector2f& v1, const Vector2f& v2) {
	v1.x *= v2.x;
	v1.y *= v2.y;
	return v1;
}
const Vector2f& operator*=(Vector2f& v, double a) {
	v.x *= a;
	v.y *= a;
	return v;
}



bool operator==(const Vector2f& v1, const Vector2f& v2) {
	return (v1.x == v2.x && v1.y == v2.y);
}

std::ostream& operator<<(std::ostream& os, const Vector2f& vector) {
	os << "[" << vector.x << ", " << vector.y << "]";
	return os;
}

Vector3f::Vector3f()
	: x(0.0), y(0.0), z(0.0)
{}

Vector3f::Vector3f(double x, double y, double z)
	: x(x), y(y), z(z)
{}

Vector3f::~Vector3f()
{}

Vector3f& Vector3f::operator=(const Vector3f& v) {
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	return (*this);
}
Vector3f operator+(const Vector3f& v1, const Vector3f& v2) {
	Vector3f result;
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return result;
}
Vector3f operator-(const Vector3f& v1, const Vector3f& v2) {
	Vector3f result;
	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return result;
}
Vector3f operator*(const Vector3f& v, double a) {
	Vector3f result;
	result.x = v.x * a;
	result.y = v.y * a;
	result.z = v.z * a;
	return result;
}
Vector3f operator*(double a, const Vector3f& v) {
	Vector3f result;
	result.x = v.x * a;
	result.y = v.y * a;
	result.z = v.z * a;
	return result;
}
Vector3f operator*(const Vector3f& v1, const Vector3f& v2) {
	Vector3f result;
	result.x = v1.x * v2.x;
	result.y = v1.y * v2.y;
	result.z = v1.z * v2.z;
	return result;
}


const Vector3f& operator+=(Vector3f& v1, const Vector3f& v2) {
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return v1;
}
const Vector3f& operator-=(Vector3f& v1, const Vector3f& v2) {
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return v1;
}
const Vector3f& operator*=(Vector3f& v1, const Vector3f& v2) {
	v1.x *= v2.x;
	v1.y *= v2.y;
	v1.z *= v2.z;
	return v1;
}
const Vector3f& operator*=(Vector3f& v, double a) {
	v.x *= a;
	v.y *= a;
	v.z *= a;
	return v;
}


bool operator==(const Vector3f& v1, const Vector3f& v2) {
	return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z);
}

std::ostream& operator<<(std::ostream& os, const Vector3f& vector) {
	return os << "[" << vector.x << ", " << vector.y << ", " << vector.z << "]";
}