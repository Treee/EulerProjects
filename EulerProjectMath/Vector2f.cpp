#include "stdafx.h"

#include "Vector2f.h"

namespace EulerTools
{

	Vector2f::operator const float*() const
	{//this assumes x and y are stored right next to eachother
		return &x;
	}

	//overloaded addition operator
	Vector2f Vector2f::operator+(const Vector2f& right) const
	{//v1(1,2) + v2(3,4) = (1+3, 2+4)
		return Vector2f(x + right.x, y + right.y);
	}

	//overloaded subtraction operator
	Vector2f Vector2f::operator-(const Vector2f& right) const
	{//v1(1,2) - v2(3,4) = (1-3, 2-4)
		return Vector2f(x - right.x, y - right.y);
	}

	//overloaded multiplication operator Vector2f*Vector2f
	Vector2f Vector2f::operator*(const Vector2f& right) const
	{//v1(1,2) * v2(3,4) = (1*3, 2*4)
		return Vector2f(x * right.x, y * right.y);
	}
	
	//overloaded multiplication operator float*Vector2f
	Vector2f Vector2f::operator*(const float scalar) const
	{//x * v1(1,2) = (1*x, 2*x)
		return Vector2f(scalar * x, scalar * y);
	}

	//overloaded multiplication operator Vector2f/Vector2f
	Vector2f Vector2f::operator/(const Vector2f& right) const
	{//v1(1,2) / v2(3,4) = (1/3, 2/4)
		return Vector2f(x / right.x, y / right.y);
	}

	//overloaded multiplication operator Vector2f/float
	Vector2f Vector2f::operator/(const float scalar) const
	{//v1(1,2) / x = (1/x, 2/x)
		return Vector2f(x / scalar, y / scalar);
	}

	//length (magnitude) of the vector
	float Vector2f::length() const
	{
		//distance formula. (square root of x^2 + y^2)
		return sqrt(lengthSquared());
	}

	//helper math function to quickly calculat the square
	float Vector2f::lengthSquared() const
	{//return length * length
		return x*x + y*y;
	}

	//returns the distance between two vectors (test this)
	float Vector2f::distanceTo(const Vector2f& somePosition) const
	{//v1(1,2) v2(3,4)
		//(v2-v1).length
		Vector2f temp = somePosition - Vector2f(x, y);
		return temp.length();
	}

	//return a normalized vector
	Vector2f Vector2f::normalize() const
	{
		float vectorLength = length();
		if (vectorLength == 0)
		{
			return Vector2f(0, 0);
		}
		return Vector2f(x / vectorLength, y / vectorLength);
	}

	Vector2f Vector2f::perpClockwise() const
	{//swap x and y and negate the second term to rotate clockwise
		//v1(1,2) --> v2(2, -1)
		return Vector2f(y, -x);
	}

	Vector2f Vector2f::perpCounterClockwise() const
	{//swap x and y and negate the first term to rotate counter clockwise
		//v1(1,2) --> v2(-2, 1)
		return Vector2f(-y, x);
	}

	float Vector2f::dot(const Vector2f vector) const
	{//v1(1,2) |dot| v2(3,4)
		//(1*3)+(2*4)
		return x*vector.x + y*vector.y;
	}

	float Vector2f::cross(const Vector2f vector) const
	{//v1(1,2) |cross| v2(3,4)
		//(1*4)-(2*3)
		return x*vector.y - y*vector.x;
	}

	//return the current x value
	float Vector2f::getX() const
	{
		return x;
	}

	//return the current y value 
	float Vector2f::getY() const
	{
		return y;
	}

	//float * Vector2f
	Vector2f operator*(float scalar, const Vector2f& vector)
	{
		return Vector2f(scalar * vector.getX(), scalar * vector.getY());
	}

	std::ostream& operator<<(std::ostream& out, const Vector2f& vector)
	{
		std::cout << ": { " << vector.getX() << ", " << vector.getY() << " }" << std::endl;
		return out;
	}
}
