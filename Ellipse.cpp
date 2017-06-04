#include <iostream>
#include <cmath>
#include "Ellipse.hpp"

Ellipse::Ellipse(ulong color, uint x, uint y, uint _height, uint _width)
 : Forme(color, x, y), height(_height), width(_width)
{
  Forme::infotime("Construction d'une Ellipse");
  cerr << "Construction d'une ellipse " << perimetre() << endl;
}

Ellipse::Ellipse(istream &is)
 : Forme(is), height(0), width(0)
{
    Forme::infotime("Construction d'une Ellipse depuis l'entrée standard ('Formes.txt')");
    bool fillsave = false;
    is >> height >> width >> fillsave;
    setFill(fillsave);
}

Ellipse::~Ellipse()
{
    Forme::infotime("Destruction de l'Ellipse");
}

double Ellipse::perimetre() const
{
	return ((2*3.14159265359)*sqrt(0.5*(((height/2)*(height/2))+((width/2)*(width/2)))));
}

void Ellipse::dessiner(EZWindow &w, bool isActive) const
{
    Forme::infotime("Dessinage de l'Ellipse");
    Forme::dessiner(w);
    if (isActive)
	     //w.fillCircle(Forme::getAnchor().getx()-width, Forme::getAnchor().gety()-height, (Forme::getAnchor().getx()+width), (Forme::getAnchor().gety()+height));
       w.fillCircle(Forme::getAnchor().getx(), Forme::getAnchor().gety(), (Forme::getAnchor().getx()+width), (Forme::getAnchor().gety()+height));
    else
	     w.drawCircle(Forme::getAnchor().getx(), Forme::getAnchor().gety(), (Forme::getAnchor().getx()+width), (Forme::getAnchor().gety()+height));
}

void Ellipse::ecrire(ostream &os) const
{
    Forme::infotime("Sauvegarde de l'Ellipse sur la sortie standard ('Formes.txt')");
	os << "Ellipse      " << getColor() << "       " << getAnchor().getx() << "      " << getAnchor().gety() << "      " << height << "      " << width;
}
