#include <iostream>
#include <cmath>
#include "Ellipse.hpp"

Ellipse::Ellipse(ulong color, uint x, uint y, uint _height, uint _width)
 : Forme(color, x, y), height(_height), width(_width)
{
  cerr << "Construction d'une Ellipse" << endl;
}

Ellipse::Ellipse(istream &is)
 : Forme(is), height(0), width(0)
{
	is >> height >> width;
}

Ellipse::~Ellipse()
{
  cerr << "Destruction de Ellipse";
}

double Ellipse::perimetre() const
{
	return (2*3.14159265359*(sqrt((1/2)*((getHeight()*getHeight())+(getWidth()*getWidth())))));
}

void Ellipse::dessiner(EZWindow &w, bool isActive) const
{
	Forme::dessiner(w);
	w.drawCircle(Forme::getAnchor().getx()-width, Forme::getAnchor().gety()-height, (Forme::getAnchor().getx()+width), (Forme::getAnchor().gety()+height));
}

void Ellipse::ecrire(ostream &os) const
{
	os << height << " " << width;
}
