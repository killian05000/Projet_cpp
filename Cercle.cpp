#include <iostream>
#include "Cercle.hpp"

Cercle::Cercle(ulong color, uint x, uint y, uint _side)
 : Forme(color, x, y), side(_side), radius(_side/2)
{
  cerr << "Construction d'un Cercle " << perimetre() << endl;
}

Cercle::Cercle(istream &is)
 : Forme(is), side(0)
{
    bool fillsave = false;
    is >> side >> fillsave;
    setFill(fillsave);
}

Cercle::~Cercle()
{
  cerr << "Destruction de Cercle" << endl;
}

double Cercle::perimetre() const
{
    return (2*3.14159265359*radius);
}

void Cercle::dessiner(EZWindow &w, bool isActive) const
{
    Forme::dessiner(w);
    if (isActive)
	w.fillCircle(Forme::getAnchor().getx()-side, Forme::getAnchor().gety()-side, Forme::getAnchor().getx()+side, Forme::getAnchor().gety()+side);
    else
	w.drawCircle(Forme::getAnchor().getx()-side, Forme::getAnchor().gety()-side, Forme::getAnchor().getx()+side, Forme::getAnchor().gety()+side);
}

void Cercle::ecrire(ostream &os) const
{
    os << "Cercle " << getColor() << " " << getAnchor().getx() << " " << getAnchor().gety() << " " << side;
}
