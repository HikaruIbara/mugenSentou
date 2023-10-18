#include "Vector2.h"

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::~Vector2()
{
}

Vector2 Vector2::operator-=(const Vector2& in)
{
	this->x -= in.x;
	this->y -= in.y;

	return (*this);
}

Vector2 Vector2::operator-(const Vector2& in)
{
	Vector2 out
	(
		this->x - in.x,
		this->y - in.y
	);
	return out;
}

Vector2 Vector2::operator+=(const Vector2& in)
{
	this->x += in.x;
	this->y += in.y;

	return (*this);
}

Vector2 Vector2::operator+(const Vector2& in)
{
	Vector2 out
	(
		this->x + in.x,
		this->y + in.y
	);
	return out;
}

Vector2 Vector2::operator*=(const Vector2& in)
{
	this->x *= in.x;
	this->y *= in.y;

	return (*this);
}

Vector2 Vector2::operator*(const Vector2& in)
{
	Vector2 out
	(
		this->x * in.x,
		this->y * in.y
	);
	return out;
}

Vector2 Vector2::operator/=(const Vector2& in)
{
	this->x /= in.x;
	this->y /= in.y;

	return (*this);
}

Vector2 Vector2::operator/(const Vector2& in)
{
	Vector2 out
	(
		this->x / in.x,
		this->y / in.y
	);
	return out;
}

Vector2 Vector2::operator++()
{
	Vector2 out
	(
		this->x++,
		this->y++
	);
	return out;
}

Vector2 Vector2::operator--()
{
	Vector2 out
	(
		this->x--,
		this->x--
	);
	return out;
}

bool Vector2::operator==(const Vector2& in) const
{
	return 	(this->x == in.x && this->y == in.y);
}

bool Vector2::operator!=(const Vector2& in) const
{
	return !(this->x == in.x && this->y == in.y);
}

void Vector2::normalize()
{
	float mag = 1 / sqrtf((float)((double)x * (double)x + (double)y * (double)y));
	x *= mag;
	y *= mag;
}

float Vector2::distance(Vector2 des)
{
	return 	sqrtf(fabsf(des.x - x) + fabsf(des.y - y));
}

void Vector2::pow(float num)
{
	x = powf(x, num);
	y = powf(y, num);
}
