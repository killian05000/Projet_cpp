#include <iostream>
#include "Triangle.hpp"

Triangle::Triangle(ulong color, uint x, uint y, uint _height, uint _width)
 : Forme(color, x, y), height(_height), width(_width)
{
        //cerr << "Construction par parametre de Triangle" << endl;
}

Triangle::Triangle(istream &is)
 : Forme(is), height(0), width(0)
{
	is >> height >> width;
}

Triangle::~Triangle()
{
        //cerr << "Destruction de Triangle";
}

double Triangle::perimetre() const
{
	return (height+width)*2;
}

void Triangle::dessiner(EZWindow &w, bool isActive) const
{
	Forme::dessiner(w);
	w.drawTriangle((Forme::getAnchor().getx()-width/2), Forme::getAnchor().gety(), (Forme::getAnchor().getx()+width/2), Forme::getAnchor().gety(), Forme::getAnchor().getx(), Forme::getAnchor().gety()-height);
}

void Triangle::ecrire(ostream &os) const
{
	os << height << " " << width;
}
