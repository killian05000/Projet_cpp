#include "Point.hpp"

Point::Point(uint _x, uint _y)
	: x(_x), y(_y)
{
	//cerr << "Construction d'un Point";
}

Point::Point(const Point &orig)
	: Point (orig.x, orig.y)
{
	//cerr << "Construction par recopie d'un Point existant";
}

Point::Point(istream &is)
	: x(0), y(0)
{
    is >> x >> y;
}

Point::~Point()
{
	//cerr << "Destruction de toutes les constructions";
}

bool Point::isOver(uint _x, uint _y)
{
	uint dx = (x < _x ? _x - x : x - _x);
	uint dy = (y < _y ? _y - y : y - _y);

	return (dx <= taille && dy <= taille);
}

void Point::dessiner(EZWindow &w, bool isActive) const
{
	// w.drawRectangle(x-10, y-10, x+10, y+10);
	// w.setThick(1);
	if (isActive)
	{
		w.fillRectangle(x-taille, y-taille, x+taille, y+taille);
		//w.setThick(1);
	}
	else
	{
		w.drawRectangle(x-taille, y-taille, x+taille, y+taille);
		//w.setThick(1);
	}
}

ostream &operator<< (ostream &os, const Point &p)
{
	os << p.x << " " << p.y;
	return os;
}

istream &operator>> (istream &is, Point &p)
{
	is >> p.x >> p.y;
	return is;
}

Point &Point::operator= (const Point &src) {
	x = src.x;
	y = src.y;
	return *this;
}
