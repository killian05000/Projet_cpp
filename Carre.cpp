#include <iostream>
#include "Carre.hpp"

Carre::Carre(ulong color, uint x, uint y, uint _side)
 : Forme(color, x, y), side(_side)
{
    //cerr << "Construction d'un Carre " << perimetre() << endl;
}

Carre::Carre(istream &is)
 : Forme(is), side(0)
{
    bool fillsave = false;
    is >> side >> fillsave;
    Forme::setFill(fillsave);
}

Carre::~Carre()
{
    //cerr << "Destruction de Carre" << endl;
}

double Carre::perimetre() const
{
    return (side * 4);
}

void Carre::dessiner(EZWindow &w, bool isActive) const
{
    Forme::dessiner(w);
    if (isActive)
	     //w.fillRectangle(Forme::getAnchor().getx()-side, Forme::getAnchor().gety()-side, Forme::getAnchor().getx()+side, Forme::getAnchor().gety()+side);
       w.fillRectangle(Forme::getAnchor().getx(), Forme::getAnchor().gety(), (Forme::getAnchor().getx()+side), (Forme::getAnchor().gety()+side));
    else
	     w.drawRectangle(Forme::getAnchor().getx(), Forme::getAnchor().gety(), (Forme::getAnchor().getx()+side), (Forme::getAnchor().gety()+side));
}

void Carre::ecrire(ostream &os) const
{
    os << "Carre " << getColor() << " " << getAnchor().getx() << " " << getAnchor().gety() << " " << side;
}
