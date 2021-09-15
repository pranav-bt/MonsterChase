#pragma once

#include<stdio.h>
#include<stdlib.h>
namespace GritEngine {
	class Point2D
	{
	public:
		Point2D(int x, int y) : xpri(x), ypri(y), z(0){}
		Point2D() : xpri(0), ypri(0), z(0){}

		//getters
		int x() const { return xpri; }
		int y() const { return ypri; }


		//setters
		void setx(int x) { xpri = x; }
		void sety(int y) { ypri = y; }
		void setposition(int x, int y) { xpri = x, ypri = y; }

		int generatex();
		int generatey();
		bool operator==(Point2D rhs);
		bool operator!=(Point2D rhs);
		Point2D operator+(Point2D& addvector);
		Point2D operator-(Point2D& subvector);
		Point2D operator*(int rhs);
		Point2D operator/(int rhs);
		Point2D operator-();
		Point2D operator+=(Point2D rhs);
		Point2D operator-=(Point2D rhs);
		Point2D operator*=(int rhs);
		Point2D operator/=(int rhs);
	private:
		int xpri; int ypri; int z;
	};

	Point2D operator*(int lhs, Point2D& rhs);
}

