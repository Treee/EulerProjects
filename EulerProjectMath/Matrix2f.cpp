#include "stdafx.h"

#include "Matrix2f.h"
#include "Vector2f.h"

namespace EulerTools
{
	//|0(1) 1(0) 2(0)|
	//|3(0) 4(1) 5(0)|
	//|6(0) 7(0) 8(1)|
	Matrix2f::Matrix2f()
	{
		setElement(0, 1);
		setElement(1, 0);
		setElement(2, 0);
		setElement(3, 0);
		setElement(4, 1);
		setElement(5, 0);
		setElement(6, 0);
		setElement(7, 0);
		setElement(8, 1);
	};

	//|0(v1.x) 1(v1.y) 2(t.x)|
	//|3(v2.x) 4(v2.y) 5(t.y)|
	//|6  (0)  7 (0)   8 (1) |
	Matrix2f::Matrix2f(Vector2f v1, Vector2f v2, Vector2f translate)
	{
		setElement(0, v1.getX());
		setElement(1, v1.getY());
		setElement(2, translate.getX());
		setElement(3, v2.getX());
		setElement(4, v2.getY());
		setElement(5, translate.getY());
		setElement(6, 0);
		setElement(7, 0);
		setElement(8, 1);
	};

	Matrix2f Matrix2f::inverse()
	{
		float det = determinant();
		if (det != 0)
		{
			float a = getElement(0);
			float b = getElement(1);
			float c = getElement(2);
			float d = getElement(3);
			float e = getElement(4);
			float f = getElement(5);
			Vector2f v1(e, -b);
			Vector2f v2(-d, a);
			float c1 = b*f - c*e;
			float f1 = c*d - a*f;
			return Matrix2f(((1 / det) * v1), ((1 / det) * v2), Vector2f(c1, f1));
		}
		else
		{
			std::cout << "Not invertable. I have returned the identity matrix to you." << std::endl;
			return Matrix2f();
		}
	}

	Matrix2f::operator const float* () const
	{
		return (float*)&matrix;
	}

	//returns the rotation matrix (make sure angle is in radians)
	Matrix2f Matrix2f::rotate(float angle)
	{
		return Matrix2f(Vector2f(cos(angle), -sin(angle)), Vector2f(sin(angle), cos(angle)), Vector2f());
	}

	//scales the matrix uniformly
	Matrix2f Matrix2f::uniformScale(float scalar)
	{
		return Matrix2f(Vector2f(scalar, 0), Vector2f(0, scalar), Vector2f());
	}

	//scales my matrix
	Matrix2f Matrix2f::scale(float x, float y)
	{
		return Matrix2f(Vector2f(x, 0), Vector2f(0, y), Vector2f());
	}
	//scales just the x
	Matrix2f Matrix2f::scaleX(float x)
	{
		return scale(x);
	}

	//scales just the y
	Matrix2f Matrix2f::scaleY(float y)
	{
		return scale(1, y);
	}

	//translates the given vector with 2 floats
	Matrix2f Matrix2f::translate(float x, float y)
	{
		return Matrix2f(Vector2f(1, 0), Vector2f(0, 1), Vector2f(x, y));
	}

	//translates the matrix with the given vector
	Matrix2f Matrix2f::translate(const Vector2f& vector)
	{
		return Matrix2f(Vector2f(1, 0), Vector2f(0, 1), Vector2f(vector.getX(), vector.getY()));
	}

	float Matrix2f::determinant() const
	{
		return ((getElement(0) * getElement(4)) - (getElement(1) * getElement(3)));
	}

	const float Matrix2f::getElement(int position) const
	{
		return matrix[position];
	}

	//returns the translation part of this matrix
	Vector2f Matrix2f::getTranslation() const
	{
		return Vector2f(getElement(2), getElement(5));
	}

	//sets the translation part of this matrix
	void Matrix2f::setTranslation(Vector2f translate)
	{
		setElement(2, translate.getX());
		setElement(5, translate.getY());
	}

	//sets the element at the given position(zero based) with the given value
	void Matrix2f::setElement(int position, float value)
	{
		matrix[position] = value;
	}

	//returns the pointer for this matrix.
	float* Matrix2f::getMatrix()
	{
		return matrix;
	}

	//Matrix2f * Matrix2f
	Matrix2f Matrix2f::operator* (const Matrix2f& right) const
	{
		// |a b c|    |q r s|   |(a*q + b*t) (a*r + b*u) (a*s + b*v + c)|
		// |d e f|  * |t u v| = |(d*q + e*t) (d*r + e*u) (d*s + e*v + f)| 
		// |g h i|    |l o r|   |    (0          (0)            (1)     |
		float a = getElement(0);
		float b = getElement(1);
		float c = getElement(2);
		float d = getElement(3);
		float e = getElement(4);
		float f = getElement(5);
		float q = right.getElement(0);
		float r = right.getElement(1);
		float s = right.getElement(2);
		float t = right.getElement(3);
		float u = right.getElement(4);
		float v = right.getElement(5);

		Vector2f v1(((a*q) + (b*t)), ((a*r) + (b*u)));
		Vector2f v2(((d*q) + (e*t)), ((d*r) + (e*u)));
		Vector2f v3(((a*s) + (b*v) + c), ((d*s) + (e*v) + f));
		return Matrix2f(v1, v2, v3);
	}

	//Matrix2f * Vector2f
	Vector2f Matrix2f::operator* (const Vector2f& right) const
	{
		//example
		// |1 2 0|    |2|   |1*2 + 2*2 + 0|   |6|
		// |3 4 0|  * |2| = |3*2 + 4*2 + 0| = |14| 
		// |0 0 1|    |1|   |      1      |   |1|
		float a = getElement(0);
		float b = getElement(1);
		float c = getElement(2);
		float d = getElement(3);
		float e = getElement(4);
		float f = getElement(5);
		float q = right.getX();
		float r = right.getY();
		return Vector2f((a*q + b*r + c), (d*q + e*r + f));
	}

	std::ostream& operator<< (std::ostream& out, const Matrix2f& matrix)
	{
		std::cout << "| " << matrix.getElement(0) << " " << matrix.getElement(1) << " " << matrix.getElement(2) << " |" << std::endl;
		std::cout << "| " << matrix.getElement(3) << " " << matrix.getElement(4) << " " << matrix.getElement(5) << " |" << std::endl;
		std::cout << "| " << matrix.getElement(6) << " " << matrix.getElement(7) << " " << matrix.getElement(8) << " |" << std::endl;
		return out;
	}
}
