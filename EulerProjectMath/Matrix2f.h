#pragma once

#include "ExportHeader.h"

#include "Vector2f.h"

namespace EulerTools
{
	class EulerTools_SHARED Matrix2f
	{
	public:
		//default ctor
		Matrix2f();

		//override ctor
		Matrix2f(Vector2f v1, Vector2f v2, Vector2f translate);

		//returns the address for x (since we can assume x and y are next to eachother we treat htem as if they were in an array)
		operator const float* () const;

		//returns the rotation matrix (make sure angle is in radians)
		static Matrix2f rotate(float angle);

		//scales the matrix uniformly
		static Matrix2f uniformScale(float scalar);

		//scales my matrix
		static Matrix2f scale(float x = 1, float y = 1);
		//scales just the x
		static Matrix2f scaleX(float x);

		//scales just the y
		static Matrix2f scaleY(float y);

		//translates the given vector with 2 floats
		static Matrix2f translate(float x, float y);
		//translates the matrix with the given vector
		static Matrix2f translate(const Vector2f& vector);

		//returns the inverse of this matrix
		Matrix2f inverse();

		//returns the determinant (a * e) - (b * d)
		float determinant() const;

		//Matrix2h * Matrix2h
		Matrix2f operator* (const Matrix2f& right) const;

		//Matrix2h * Vector2f
		Vector2f operator* (const Vector2f& right) const;

		//returns the float at the specified position of the array (zero based)
		const float getElement(int position) const;

		//returns the translation part of this matrix
		Vector2f getTranslation() const;

		//sets the translation part of this matrix
		void setTranslation(Vector2f translate);

		//sets the element at the given position(zero based) with the given value
		void setElement(int position, float value);

		//returns the pointer for this matrix.
		float* getMatrix();
		//my friendly toString
		friend EulerTools_SHARED std::ostream& operator<< (std::ostream& out, const Matrix2f& matrix);


	private:
		float matrix[9];

	};

}