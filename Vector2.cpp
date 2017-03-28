#include "Vector2.h"
#include <cmath>
#include <string>

Vector2::Vector2(double a, double b)
{
	x = a;
	y = b;
}

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2 Vector2::operator+(const Vector2& v2)
{
	Vector2 temp(x + v2.x, y + v2.y);
	return temp;
}

Vector2 Vector2::operator-(const Vector2& v2)
{
	Vector2 temp(x - v2.x, y - v2.y);
	return temp;
}

Vector2 Vector2::operator*(const Vector2& v2)
{
	Vector2 temp(x * v2.x, y * v2.y);
	return temp;
}

Vector2 Vector2::operator*(const double& scalar)
{
	Vector2 temp(x * scalar, y * scalar);
	return temp;
}

Vector2 Vector2::operator/(const double& scalar)
{
	Vector2 temp(x / scalar, y / scalar);
	return temp;
}

double Vector2::operator++(int)
{
	double mag = sqrt(x*x + y*y);
	//Vector2 temp(mag, 0);
	return mag;
}

Vector2 Vector2::operator--(int)
{
	Vector2 temp(x, y);
	double tempMag = (temp++);//.x;
	temp = temp / tempMag;
	return temp;
}

std::string Vector2::toString()
{
	std::string temp = "X: " + std::to_string(x) + ", Y: " + std::to_string(y);
	return temp;
}

Vector2::~Vector2()
{
}
