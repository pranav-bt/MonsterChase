#include "Point2D.h"

namespace GritEngine {

	int Point2D::generatex()
	{
		int x;
		x = rand() % 100;
		return x;
	}
	int Point2D::generatey()
	{
		int y;
		y = rand() % 100;
		return y;
	}

	bool Point2D::operator==(Point2D rhs)
	{
		if (xpri == rhs.x() && ypri == rhs.y())
		{
			return true;
		}
		else { return false; }
	}

	bool Point2D::operator!=(Point2D rhs)
	{
		if (xpri != rhs.x() || ypri != rhs.y())
		{
			return true;
		}
		else { return false; }
	}

	Point2D Point2D::operator+(Point2D& addvector)
	{
		return Point2D(xpri + addvector.x(), ypri + addvector.y());
	}

	Point2D Point2D::operator-(Point2D& subvector)
	{
		return Point2D(xpri - subvector.x(), ypri - subvector.y());
	}

	Point2D Point2D::operator*(int rhs)
	{
		return Point2D(xpri * rhs, ypri * rhs);
	}

	Point2D Point2D::operator/(int rhs)
	{
		return Point2D(xpri / rhs, ypri / rhs);
	}
	Point2D Point2D::operator-()
	{
		return Point2D(-xpri, -ypri);
	}
	Point2D Point2D::operator+=(Point2D rhs)
	{
		xpri += rhs.x();
		ypri += rhs.y();
		return *this;
	}
	Point2D Point2D::operator-=(Point2D rhs)
	{
		xpri -= rhs.x();
		ypri -= rhs.y();
		return *this;
	}
	Point2D Point2D::operator*=(int rhs)
	{
		xpri *= rhs;
		ypri *= rhs;
		return *this;
	}
	Point2D Point2D::operator/=(int rhs)
	{
		xpri /= rhs;
		ypri /= rhs;
		return *this;
	}
	Point2D operator*(int lhs, Point2D& rhs)
	{
		return Point2D(rhs*lhs);
	}
}