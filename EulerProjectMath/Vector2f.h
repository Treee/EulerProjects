#pragma once

#include "ExportHeader.h"

namespace EulerTools
{
	class EulerTools_SHARED Vector2f
	{
	public:
		//default constructor that initializes x and y to 0
		Vector2f() : x(0), y(0){};

		Vector2f(float xValue, float yValue) : x(xValue), y(yValue) {};

		//return the address for x. (x and y are next to eachother)
		operator const float* () const;

		//Vector2f + Vector2f
		Vector2f operator+ (const Vector2f& right) const;
		
		//Vector2f - Vector2f
		Vector2f operator- (const Vector2f& right) const;
		
		//Vector2f * Vector2f
		Vector2f operator* (const Vector2f& right) const;
		
		//Vector2f * float
		Vector2f operator* (const float scalar) const;

		//float * Vector2f
		friend EulerTools_SHARED Vector2f operator* (float scalar, const Vector2f& vector);

		//friendly toString
		friend EulerTools_SHARED std::ostream& operator<< (std::ostream& out, const Vector2f& vector);
		
		//Vector2f / Vector2f
		Vector2f operator/ (const Vector2f& right) const;
		
		//Vector2f + float
		Vector2f operator/ (const float scalar) const;

		//length (magnitude) of the vector
		float length() const;

		//returns length * length
		float lengthSquared() const;

		//returns the distance this vector is from somePosition
		float distanceTo(const Vector2f& somePosition) const;

		//returns a normalized vector of this vector
		Vector2f normalize() const;

		//returns a vector rotated 90 degrees clockwise from "this" current vector
		Vector2f perpClockwise() const;
		
		//returns a vector rotated 90 degrees counter clockwise from "this" current vector
		Vector2f perpCounterClockwise() const;

		//returns the dot product of this vector and another
		float dot(const Vector2f vector) const;

		//returns the cross product of this vector and another
		float cross(const Vector2f vector) const;

		float getX() const;

		float getY() const;

	private:
		float x;
		float y;
	};

}
