#include <iostream>
#include <cmath>
#include "Triangle.hpp"

Triangle::Triangle(ulong color, uint x, uint y, uint _height, uint _width)
 : Forme(color, x, y), height(_height), width(_width)
{
    cerr << "Construction d'un Triangle " << perimetre() << endl;
}

Triangle::Triangle(istream &is)
 : Forme(is), height(0), width(0)
{
    is >> height >> width;
}

Triangle::~Triangle()
{
    cerr << "Destruction de Triangle" << endl;
}

double Triangle::perimetre() const
{
    return (sqrt((height*height)+(width/2)*(width/2))*2+width);
}

void Triangle::dessiner(EZWindow &w, bool isActive) const
{
    Forme::dessiner(w);
    if (isActive)
	w.fillTriangle((Forme::getAnchor().getx()-width/2), Forme::getAnchor().gety(), (Forme::getAnchor().getx()+width/2), Forme::getAnchor().gety(), Forme::getAnchor().getx(), Forme::getAnchor().gety()-height);
    else
	w.drawTriangle((Forme::getAnchor().getx()-width/2), Forme::getAnchor().gety(), (Forme::getAnchor().getx()+width/2), Forme::getAnchor().gety(), Forme::getAnchor().getx(), Forme::getAnchor().gety()-height);
}

void Triangle::ecrire(ostream &os) const
{
    os << "Triangle " << getColor() << " " << getAnchor().getx() << " " << getAnchor().gety() << " " << height << " " << width;
}
