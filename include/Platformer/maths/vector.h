#ifndef PLATFORMER_VECTOR_H
#define PLATFORMER_VECTOR_H

#include <iostream>

class Vector2f {
public:
	double x, y;

	Vector2f();
	Vector2f(double x, double y);
	~Vector2f();

	friend Vector2f operator+(const Vector2f& v1, const Vector2f& v2);
	friend Vector2f operator-(const Vector2f& v1, const Vector2f& v2);
	friend Vector2f operator*(const Vector2f& v, double a);
	friend Vector2f operator*(double a, const Vector2f& v);
	friend Vector2f operator*(const Vector2f& v1, const Vector2f& v2);

	friend const Vector2f& operator+=(Vector2f& v1, const Vector2f& v2);
	friend const Vector2f& operator-=(Vector2f& v1, const Vector2f& v2);
	friend const Vector2f& operator*=(Vector2f& v1, const Vector2f& v2);
	friend const Vector2f& operator*=(Vector2f& v, double a);

	friend bool operator==(const Vector2f& v1, const Vector2f& v2);
	friend std::ostream& operator<<(std::ostream& os, const Vector2f& vector);
};

class Vector3f {
public:
	double x, y, z;

	Vector3f();
	Vector3f(double x, double y, double z);
	~Vector3f();

	friend Vector3f operator+(const Vector3f& v1, const Vector3f& v2);
	friend Vector3f operator-(const Vector3f& v1, const Vector3f& v2);
	friend Vector3f operator*(const Vector3f& v, double a);
	friend Vector3f operator*(double a, const Vector3f& v);
	friend Vector3f operator*(const Vector3f& v1, const Vector3f& v2);

	friend const Vector3f& operator+=(Vector3f& v1, const Vector3f& v2);
	friend const Vector3f& operator-=(Vector3f& v1, const Vector3f& v2);
	friend const Vector3f& operator*=(Vector3f& v1, const Vector3f& v2);
	friend const Vector3f& operator*=(Vector3f& v, double a);

	friend bool operator==(const Vector3f& v1, const Vector3f& v2);
	friend std::ostream& operator<<(std::ostream& os, const Vector3f& vector);
};

#endif // PLATFORMER_VECTOR_H