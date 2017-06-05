#include <iostream>
#include "Cercle.hpp"

Cercle::Cercle(ulong color, uint x, uint y, uint _side)
 : Forme(color, x, y), side(_side), radius(_side/2)
{
    Forme::infotime("Construction d'un Cercle");
    cerr << "Construction d'un cercle " << perimetre() << endl;
}

Cercle::Cercle(istream &is)
 : Forme(is), side(0)
{
    bool fillsave = false;
	uint thicknesssave = 0;
    is >> side >> fillsave >> thicknesssave;
	setThickness(thicknesssave);
    setFill(fillsave);
}

Cercle::~Cercle()
{
    Forme::infotime("Destruction de Cercle");
}

double Cercle::perimetre() const
{
  //return radius;
  //return side;
  return ((2*3.14159265359)*radius);
}

void Cercle::dessiner(EZWindow &w, bool isActive) const
{
    Forme::dessiner(w);
    if (isActive)
      //w.fillCircle(Forme::getAnchor().getx()-side, Forme::getAnchor().gety()-side, Forme::getAnchor().getx()+side, Forme::getAnchor().gety()+side);
      w.fillCircle(Forme::getAnchor().getx(), Forme::getAnchor().gety(), (Forme::getAnchor().getx()+side), (Forme::getAnchor().gety()+side));
    else
      w.drawCircle(Forme::getAnchor().getx(), Forme::getAnchor().gety(), (Forme::getAnchor().getx()+side), (Forme::getAnchor().gety()+side));
}

void Cercle::ecrire(ostream &os) const
{
    Forme::infotime("Sauvegarde du Cercle sur la sortie standard ('Formes.txt')");
	os << "Cercle       " << getColor() << "       " << getAnchor().getx() << "      " << getAnchor().gety() << "      " << side;
}
