#pragma once

#include "ExportHeader.h"
#include <ostream>

namespace EulerMath
{
	class EULERMATH_SHARED Vector2
	{
	public:
		//default constructor that initializes x and y to 0
		Vector2() : x(0), y(0){};

		Vector2(float xValue, float yValue) : x(xValue), y(yValue) {};

		//return the address for x. (x and y are next to eachother)
		operator const float* () const;

		//Vector2 + Vector2
		Vector2 operator+ (const Vector2& right) const;
		
		//Vector2 - Vector2
		Vector2 operator- (const Vector2& right) const;
		
		//Vector2 * Vector2
		Vector2 operator* (const Vector2& right) const;
		
		//Vector2 * float
		Vector2 operator* (const float scalar) const;

		//float * Vector2
		friend EULERMATH_SHARED Vector2 operator* (float scalar, const Vector2& vector);

		//friendly toString
		friend EULERMATH_SHARED std::ostream& operator<< (std::ostream& out, const Vector2& vector);
		
		//Vector2 / Vector2
		Vector2 operator/ (const Vector2& right) const;
		
		//Vector2 + float
		Vector2 operator/ (const float scalar) const;

		//length (magnitude) of the vector
		float length() const;

		//returns length * length
		float lengthSquared() const;

		//returns the distance this vector is from somePosition
		float distanceTo(const Vector2& somePosition);

		//returns a normalized vector of this vector
		Vector2 normalize();

		//returns a vector rotated 90 degrees clockwise from "this" current vector
		Vector2 perpClockwise();
		
		//returns a vector rotated 90 degrees counter clockwise from "this" current vector
		Vector2 perpCounterClockwise();

		//returns the dot product of this vector and another
		float dot(const Vector2 vector) const;

		//returns the cross product of this vector and another
		float cross(const Vector2 vector) const;

		float getX() const;

		float getY() const;

	private:
		float x;
		float y;
	};

}
