#include <iostream>
#include "Forme.hpp"
#include "Rectangle.hpp"

Forme::Forme (ulong _color, uint _x, uint _y)
	: color(_color), anchor(_x, _y)
{
	cerr << "Construction complete de Forme";
}

Forme::Forme (const Forme &orig)
	: Forme (orig.color, orig.anchor.getx(), orig.anchor.gety())
{
	cerr << "Construction par recopie d'une Forme deja existante";
}

Forme::Forme(istream &is)
	: color(0), anchor(0,0)
{
	is >> color >> anchor;
}

Forme::~Forme()
{
	cerr << "Destruction de Forme";
}

//Autres formes de constructeurs

/*

Forme::Forme (const uint _color, const Point &_p)
	:color(_color), anchor(_p)
{
	cerr << "Construction complete de Forme par une Point";
}

Forme::Forme (const uint _color, uint _x, uint _y)
	: Forme (_c, Point (_x, _y))
{
	cerr << "Construction complete de Forme"
}

Forme::Forme (const Forme &f)
	: Forme (f.color, f.anchor)
{
	cerr << "Construction par recopie de Forme"
}

*/

void Forme::setAnchor(Point p) {
	anchor = p;
}

bool Forme::isOver(uint x, uint y)
{
	return anchor.isOver(x,y);
}

void Forme::dessiner(EZWindow &w, bool isActive) const
{
	w.setColor(ez_black);
	anchor.dessiner(w, isActive);
	w.setColor(color);
}

void Forme::ecrire(ostream &os) const
{
	os << color << " " << anchor;
}

ostream &operator<<(ostream &os, const Forme &f)
{
	f.ecrire(os);
	return os;
}

Forme *Forme::charger(istream &is)
{
	string type_forme;
	is >> type_forme;
	if (type_forme == "Rectangle")
		return new Rectangle(is);
	/*else if (type_forme == "Ellipse")
		return new Ellipse(is);
	else if (type_forme == "Carre")
		return new Carre(is);
	else if (type_forme == "Cercle")
		return new Cercle(is);*/
	else
		throw runtime_error ("Type de forme inconnu");
}
