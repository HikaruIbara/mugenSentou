#include "Vector3.h"

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::~Vector3()
{
}

Vector3 Vector3::operator-=(const Vector3& in)
{

	this->x -= in.x;
	this->y -= in.y;
	this->z -= in.z;

	return (*this);

}

Vector3 Vector3::operator-(const Vector3& in)
{
	Vector3 out
	(
		this->x - in.x,
		this->y - in.y,
		this->z - in.z
	);
	return out;
}

Vector3 Vector3::operator+=(const Vector3& in)
{
	this->x += in.x;
	this->y += in.y;
	this->z += in.z;

	return (*this);
}

Vector3 Vector3::operator+(const Vector3& in)
{
	Vector3 out
	(
		this->x + in.x,
		this->y + in.y,
		this->z + in.z
	);
	return out;
}

Vector3 Vector3::operator*=(const Vector3& in)
{
	this->x *= in.x;
	this->y *= in.y;
	this->z *= in.z;

	return (*this);
}

Vector3 Vector3::operator*(const Vector3& in)
{
	Vector3 out
	(
		this->x * in.x,
		this->y * in.y,
		this->z * in.z
	);
	return out;
}

Vector3 Vector3::operator/=(const Vector3& in)
{
	this->x /= in.x;
	this->y /= in.y;
	this->z /= in.z;

	return (*this);
}

Vector3 Vector3::operator/(const Vector3& in)
{
	Vector3 out
	(
		this->x / in.x,
		this->y / in.y,
		this->z / in.z
	);
	return out;
}

void Vector3::operator++()
{
	this->x++;
	this->y++;
	this->z++;
}

void Vector3::operator--()
{
	this->x--;
	this->y--;
	this->z--;
}

void Vector3::normalize()
{
	float mag = 1 / sqrtf((double)x * (double)x + (double)y * (double)y + (double)z * (double)z);
	x *= mag;
	y *= mag;
	z *= mag;
}

float Vector3::distance(Vector3 des)
{
	return 	sqrtf(fabsf(des.x-x)+fabsf(des.y-y)+fabsf(des.z-z));
}

void Vector3::pow(float num)
{
	x = powf(x, num);
	y = powf(y, num);
	z = powf(z, num);
}
