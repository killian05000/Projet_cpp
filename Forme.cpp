#include <iostream>
#include "Forme.hpp"
#include "Rectangle.hpp"
#include "Cercle.hpp"
#include "Carre.hpp"
#include "Ellipse.hpp"
#include "Triangle.hpp"

Forme::Forme (ulong _color, uint _x, uint _y)
	: color(_color), anchor(_x, _y), log("Session.log")
{
    infotime(Forme::log, " - Création d'une forme.");
    //cerr << "Construction complete de Forme";
}

Forme::Forme (const Forme &orig)
	: Forme (orig.color, orig.anchor.getx(), orig.anchor.gety())
{
    //cerr << "Construction par recopie d'une Forme deja existante";
}

Forme::Forme(istream &is)
	: color(0), anchor(0,0)
{
    is >> color >> anchor;
}

Forme::~Forme()
{
	//cerr << "Destruction de Forme" << endl;
}

/* Autres formes de constructeurs

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

void Forme::setAnchor(Point p)
{
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
    os << "Forme " << color << " " << anchor;
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
    {
	//infotime(log, " - Création d'un Rectangle.");
	return new Rectangle(is);
    }
    else if (type_forme == "Ellipse")
	return new Ellipse(is);
    else if (type_forme == "Carre")
	return new Carre(is);
    else if (type_forme == "Cercle")
	return new Cercle(is);
    else if (type_forme == "Triangle")
	return new Triangle(is);
    else
	throw runtime_error ("Type de forme inconnu");
}

void Forme::infotime(ostream &os, string message)
{
    time_t rawtime;
    struct tm timeinfo;

    time(&rawtime);
    timeinfo = *localtime(&rawtime);

    os << "Le ";

    if (timeinfo.tm_mday < 10)
	os << "0" << timeinfo.tm_mday << "/";
    else
	os << timeinfo.tm_mday << "/";

    if (timeinfo.tm_mon < 10)
	os << "0" << timeinfo.tm_mon;
    else
	os << timeinfo.tm_mon;

    os << "/" << timeinfo.tm_year+1900 << " à ";

    if (timeinfo.tm_hour < 10)
	os << "0" + timeinfo.tm_hour << ":";
    else
	os << timeinfo.tm_hour << ":";

    if (timeinfo.tm_min < 10)
	os << "0" << timeinfo.tm_min << ":";
    else
	os << timeinfo.tm_min << ":";

    if (timeinfo.tm_sec < 10)
	os << "0" << timeinfo.tm_sec;
    else
	os << timeinfo.tm_sec;

    os << " " << message << endl;
}
