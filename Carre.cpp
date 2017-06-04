#include <iostream>
#include "Carre.hpp"

Carre::Carre(ulong color, uint x, uint y, uint _side)
 : Forme(color, x, y), side(_side)
{
    Forme::infotime("Construction d'un Carre");
	cerr << perimetre();
}

Carre::Carre(istream &is)
 : Forme(is), side(0)
{
    Forme::infotime("Construction d'un Carré depuis l'entrée standard ('Formes.txt')");
    bool fillsave = false;
    is >> side >> fillsave;
    Forme::setFill(fillsave);
}

Carre::~Carre()
{
    Forme::infotime("Destruction de Carre");
}

double Carre::perimetre() const
{
    return (side * 4);
}

void Carre::dessiner(EZWindow &w, bool isActive) const
{
    Forme::infotime("Dessinage du Carré");
    Forme::dessiner(w);
    if (isActive)
	     //w.fillRectangle(Forme::getAnchor().getx()-side, Forme::getAnchor().gety()-side, Forme::getAnchor().getx()+side, Forme::getAnchor().gety()+side);
       w.fillRectangle(Forme::getAnchor().getx(), Forme::getAnchor().gety(), (Forme::getAnchor().getx()+side), (Forme::getAnchor().gety()+side));
    else
	     w.drawRectangle(Forme::getAnchor().getx(), Forme::getAnchor().gety(), (Forme::getAnchor().getx()+side), (Forme::getAnchor().gety()+side));
}

void Carre::ecrire(ostream &os) const
{
    Forme::infotime("Sauvegarde du Carré sur la sortie standard ('Formes.txt')");
    os << "Carre " << getColor() << " " << getAnchor().getx() << " " << getAnchor().gety() << " " << side;
}
