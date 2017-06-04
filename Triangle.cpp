#include <iostream>
#include <cmath>
#include "Triangle.hpp"

Triangle::Triangle(ulong color, uint _x1, uint _y1, uint _x2, uint _y2, uint _x3, uint _y3)
	: Forme(color, _x1, _y1), x2(_x2), y2(_y2), x3(_x3), y3(_y3)
{
	Forme::infotime("Construction d'un Triangle");
	cerr << perimetre();
}

Triangle::Triangle(istream &is)
 : Forme(is), x1(0), y1(0), x2(0), y2(0), x3(0), y3(0)
{
    Forme::infotime("Construction du Triangle à partir de l'entrée standard ('Formes.txt')");
    bool fillsave = false;
    is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> fillsave;
    setFill(fillsave);
}

Triangle::~Triangle()
{
    Forme::infotime("Destruction de Triangle");
}

double Triangle::perimetre() const
{
	return ((sqrt(((getx2() - getx1())*(getx2() - getx1())) + ((gety2() - gety1())* (gety2() - gety1())))) + (sqrt(((getx3() - getx2())*(getx3() - getx2())) + ((gety3() - gety2())* (gety3() - gety2())))) + (sqrt(((getx1() - getx3())*(getx1() - getx3())) + ((gety1() - gety3())* (gety1() - gety3())))));

}

void Triangle::dessiner(EZWindow &w, bool isActive) const
{
    Forme::infotime("Dessinage du Triangle");
    Forme::dessiner(w);
	
	
	if (isActive)
		w.fillTriangle(Forme::getAnchor().getx(), Forme::getAnchor().gety(), (Forme::getAnchor().getx() - x2 / 2), (Forme::getAnchor().gety() + y2), (Forme::getAnchor().getx() + x3 / 2), (Forme::getAnchor().gety() + y3));
	else
		
	    w.drawTriangle(Forme::getAnchor().getx(), Forme::getAnchor().gety(), (Forme::getAnchor().getx()-x2/2), (Forme::getAnchor().gety()+y2), (Forme::getAnchor().getx()+x3/2), (Forme::getAnchor().gety()+y3));
}

void Triangle::ecrire(ostream &os) const
{
    Forme::infotime("Sauvegarde du Triangle sur la sortie standard ('Formes.txt')");
    os << "Triangle " << getColor() << " " << getx1() << " " << gety1() << " " << getx2() << " " << gety2() << " " << getx3() << " " << gety3();
}
