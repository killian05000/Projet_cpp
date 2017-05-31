#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "ez-draw++.hpp"

using namespace std;

typedef unsigned int uint;
typedef unsigned long int ulong;

class Point {

	private :
		static const uint taille = 3;
		uint x, y;

	public :
		Point (uint x, uint y);
		Point (const Point &org);
		Point (istream &is);
		~Point();
		inline uint getx() const {return x;}
		inline uint gety() const {return y;}
		void setxy (uint x, uint y);
		bool isOver (uint _x, uint _y);
		void dessiner (EZWindow &w, bool isActive = false) const;
		friend ostream &operator<<(ostream &os, const Point &p);
		friend istream &operator>>(istream &is, Point &p);
		Point &operator= (const Point &src);
};

#endif
