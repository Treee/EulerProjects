#include "stdafx.h"

#include "Vector3f.h"

namespace EulerTools
{

	Vector3f::operator const float*() const
	{//this assumes x and y are stored right next to eachother
		return &x;
	}

	//overloaded addition operator
	Vector3f Vector3f::operator+(const Vector3f& right) const
	{//v1(1,2,3) + v2(4,5,6) = (1+4, 2+5, 3+6)
		return Vector3f(x + right.x, y + right.y, z + right.z);
	}

	//overloaded subtraction operator
	Vector3f Vector3f::operator-(const Vector3f& right) const
	{//v1(1,2,3) - v2(4,5,6) = (1-4, 2-5, 3-6)
		return Vector3f(x - right.x, y - right.y, z - right.z);
	}

	//overloaded multiplication operator Vector3f*Vector3f
	Vector3f Vector3f::operator*(const Vector3f& right) const
	{//v1(1,2,3) * v2(4,5,6) = (1*4, 2*5, 3*6)
		return Vector3f(x * right.x, y * right.y, z * right.z);
	}

	//overloaded multiplication operator float*Vector3f
	Vector3f Vector3f::operator*(const float scalar) const
	{//x * v1(1,2,3)= (1*x, 2*x, 3*x)
		return Vector3f(scalar * x, scalar * y, scalar * z);
	}

	//overloaded multiplication operator Vector3f/Vector3f
	Vector3f Vector3f::operator/(const Vector3f& right) const
	{//v1(1,2,3) / v2(4,5,6) = (1/4, 2/5, 3/6)
		return Vector3f(x / right.x, y / right.y, z/ right.z);
	}

	//overloaded multiplication operator Vector3f/float
	Vector3f Vector3f::operator/(const float scalar) const
	{//v1(1,2,3)/x = (1+4, 2+5, 3+6)
		return Vector3f(x / scalar, y / scalar, z/scalar);
	}

	//length (magnitude) of the vector
	float Vector3f::length() const
	{
		//distance formula. (square root of x^2 + y^2 + z^2)
		return sqrt(lengthSquared());
	}

	//helper math function to quickly calculat the square
	float Vector3f::lengthSquared() const
	{//return length * length
		return x*x + y*y + z*z;
	}

	//returns the distance between two vectors (test this)
	float Vector3f::distanceTo(const Vector3f& somePosition) const
	{//v1(1,2) v2(3,4)
	 //(v2-v1).length
		Vector3f temp = somePosition - Vector3f(x, y, z);
		return temp.length();
	}

	//return a normalized vector
	Vector3f Vector3f::normalize() const
	{
		float vectorLength = length();
		if (vectorLength == 0)
		{
			return Vector3f(0, 0, 0);
		}
		return Vector3f(x / vectorLength, y / vectorLength, z / vectorLength);
	}

	float Vector3f::dot(const Vector3f vector) const
	{//v1(1,2,3) |dot| v2(4,5,6)
	 //(1*4)+(2*5)+(3*6)
		return x*vector.x + y*vector.y + z*vector.z;
	}

	Vector3f Vector3f::cross(const Vector3f vector) const
	{//v1(ax, ay, az) |cross| v2(bx, by,bz)
	 //(ay*bz-az*by), (az*bx-ax*bz), (ax*by-ay*bx)
		return Vector3f( y*vector.z - z*vector.y, z*vector.x - x*vector.z, x*vector.y - y*vector.x ); 
	}

	//return the current x value
	float Vector3f::getX() const
	{
		return x;
	}

	//return the current y value 
	float Vector3f::getY() const
	{
		return y;
	}

	//return the current z value
	float Vector3f::getZ() const
	{
		return z;
	}

	//float * Vector3f
	Vector3f operator*(float scalar, const Vector3f& vector)
	{
		return Vector3f(scalar * vector.getX(), scalar * vector.getY(), scalar * vector.getZ());
	}

	std::ostream& operator<<(std::ostream& out, const Vector3f& vector)
	{
		std::cout << ": { " << vector.getX() << ", " << vector.getY() << ", " << vector.getZ() << " }" << std::endl;
		return out;
	}
}
