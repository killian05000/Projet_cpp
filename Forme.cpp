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
    //Création d'une Forme
}

Forme::Forme (const Forme &orig)
	: Forme (orig.color, orig.anchor.getx(), orig.anchor.gety())
{
    //Construction par recopie d'une Forme deja existante.
}

Forme::Forme(istream &is)
	: color(0), anchor(0,0)
{
    //Construction, par l'entrée standard, d'une Forme depuis le fichier 'Formes.txt'
    is >> color >> anchor;
}

Forme::~Forme()
{
    //Destructeur de Forme
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
    //Déclaration d'une ancre comme un point
    anchor = p;
}

bool Forme::isOver(uint x, uint y)
{
    //permet de vérifier si l'utilisateur clique sur l'ancre ou pas
    return anchor.isOver(x,y);
}

void Forme::dessiner(EZWindow &w, bool isActive) const
{

    //Permet de déssiner la forme voulu
    w.setColor(ez_red);
    w.setThick(1);
    anchor.dessiner(w, isActive);
    w.setThick(thickness);
    w.setColor(color);
}
void Forme::ecrire(ostream &os) const
{
    infotime("Enregistrement de la Forme dans la sortie standard ('Formes.txt').");
    os << "Forme " << color << " " << anchor;
}

ostream &operator<<(ostream &os, const Forme &f)
{
    //Opérateur permettant de sauvegarder la Forme sur la sortie standard ('Formes.txt')
    f.ecrire(os);
    return os;
}

Forme *Forme::charger(istream &is)
{
    //Fonction permettant de charger une forme depuis l'entrée standard ('Formes.txt')
    string type_forme;
    is >> type_forme;
    if (type_forme == "Rectangle")
	return new Rectangle(is);
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

void Forme::infotime(string message) const
{
    //Fonction permettant de structurer le fichier log ('Session.log') avec l'heure, la date et un message personnalisé (passé en parametre)
    std::ofstream log("Session.log", std::ofstream::app);

    if (!log) {	cerr << "Echec lors de l'eriture dans le fichier 'Session.log'."; return; }

    time_t rawtime;
    struct tm timeinfo;

    time(&rawtime);
    timeinfo = *localtime(&rawtime);

    log << "Le ";

	//Date : Jour
    if(timeinfo.tm_mday < 10)
		log << "0" << timeinfo.tm_mday << "/";
    else
		log << timeinfo.tm_mday << "/";

	//Date : Mois
    if (timeinfo.tm_mon < 10)
		log << "0" << timeinfo.tm_mon;
    else
		log << timeinfo.tm_mon;

	//Date : Année
    log << "/" << timeinfo.tm_year+1900 << " à ";

	//Date : Heure
    if (timeinfo.tm_hour < 10)
		log << "0" + timeinfo.tm_hour << ":";
    else
		log << timeinfo.tm_hour << ":";

	//Date : Minute
    if (timeinfo.tm_min < 10)
		log << "0" << timeinfo.tm_min << ":";
    else
		log << timeinfo.tm_min << ":";

	//Date : Seconde
    if (timeinfo.tm_sec < 10)
		log << "0" << timeinfo.tm_sec;
    else
		log << timeinfo.tm_sec;

    log << " - " << message << "." << endl;

    log.close();
}
