#include <iostream>
#include "Rectangle.hpp"

Rectangle::Rectangle(ulong color, uint x, uint y, uint _height, uint _width)
 : Forme(color, x, y), height(_height), width(_width)
{
  cerr << "Construction d'un Rectangle " << perimetre() << endl;
}

Rectangle::Rectangle(istream &is)
 : Forme(is), height(0), width(0)
{
	is >> height >> width;
}

Rectangle::~Rectangle()
{
  cerr << "Destruction de Rectangle" << endl;
}

double Rectangle::perimetre() const
{
	return ((height+width)*2);
}

void Rectangle::dessiner(EZWindow &w, bool isActive) const
{
	Forme::dessiner(w);
	if (isActive)
	    w.fillRectangle((Forme::getAnchor().getx()-width/2), (Forme::getAnchor().gety()-height/2), (Forme::getAnchor().getx()+width/2), (Forme::getAnchor().gety()+height/2));
	else
	    w.drawRectangle((Forme::getAnchor().getx()-width/2), (Forme::getAnchor().gety()-height/2), (Forme::getAnchor().getx()+width/2), (Forme::getAnchor().gety()+height/2));
}

void Rectangle::ecrire(ostream &os) const
{
	os << "Rectangle " << getColor() << " " << getAnchor().getx() << " " << getAnchor().gety() << " " << height << " " << width;
}
