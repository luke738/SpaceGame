#pragma once
#include <string>
class Vector2
{
public:
	double x;
	double y;
	Vector2 operator+ (const Vector2&);
	Vector2 operator- (const Vector2&);
	Vector2 operator* (const Vector2&);  //Dot Product
	Vector2 operator* (const double&);
	Vector2 operator/ (const double&);
	double operator++ (int);    //vec++.x == mag(vec)
	Vector2 operator-- (int);   //vec-- == norm(vec)
	std::string toString();
	Vector2(double a, double b);
	Vector2();
	~Vector2();
};

