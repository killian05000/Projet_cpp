#include <iostream>
#include <cmath>
#include "Ellipse.hpp"

Ellipse::Ellipse(ulong color, uint x, uint y, uint _height, uint _width)
 : Forme(color, x, y), height(_height), width(_width)
{
<<<<<<< HEAD
  cerr << "Construction d'une Ellipse " << perimetre() << endl;
=======

    cerr << "Construction d'une Ellipse" << endl;
    cerr << perimetre();

>>>>>>> 694a384778e20f641618d27893b7187f831517cd
}

Ellipse::Ellipse(istream &is)
 : Forme(is), height(0), width(0)
{
    is >> height >> width;
}

Ellipse::~Ellipse()
{
<<<<<<< HEAD
  cerr << "Destruction de Ellipse" << endl;
=======
    cerr << "Destruction de Ellipse";
>>>>>>> 694a384778e20f641618d27893b7187f831517cd
}

double Ellipse::perimetre() const
{
<<<<<<< HEAD
	return ((2*3.14159265359)*sqrt(0.5*(((height/2)*(height/2))+((width/2)*(width/2)))));
=======
    return (2*3.14159265359*(sqrt((1/2)*((getHeight()*getHeight())+(getWidth()*getWidth())))));
>>>>>>> 694a384778e20f641618d27893b7187f831517cd
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
