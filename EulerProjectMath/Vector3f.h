#pragma once

#include "ExportHeader.h"

namespace EulerTools
{
	class EulerTools_SHARED Vector3f
	{
	public:
		//default constructor that initializes x, y and z to 0
		Vector3f() : x(0), y(0), z(0){}

		Vector3f(float xValue, float yValue, float zValue) : x(xValue), y(yValue), z(zValue) {}

		//return the address for x. (x, y, and z are next to eachother)
		operator const float* () const;

		//Vector3f + Vector3f
		Vector3f operator+ (const Vector3f& right) const;

		//Vector3f - Vector3f
		Vector3f operator- (const Vector3f& right) const;

		//Vector3f * Vector3f
		Vector3f operator* (const Vector3f& right) const;

		//Vector3f * float
		Vector3f operator* (const float scalar) const;

		//float * Vector3f
		friend EulerTools_SHARED Vector3f operator* (float scalar, const Vector3f& vector);

		//friendly toString
		friend EulerTools_SHARED std::ostream& operator<< (std::ostream& out, const Vector3f& vector);

		//Vector3f / Vector3f
		Vector3f operator/ (const Vector3f& right) const;

		//Vector3f + float
		Vector3f operator/ (const float scalar) const;

		//length (magnitude) of the vector
		float length() const;

		//returns length * length
		float lengthSquared() const;

		//returns the distance this vector is from somePosition
		float distanceTo(const Vector3f& somePosition) const;

		//returns a normalized vector of this vector
		Vector3f normalize() const;		

		//returns the dot product of this vector and another
		float dot(const Vector3f vector) const;

		//returns the cross product of this vector and another
		Vector3f cross(const Vector3f vector) const;

		float getX() const;

		float getY() const;

		float getZ() const;

	private:
		float x;
		float y;
		float z;
	};

}
