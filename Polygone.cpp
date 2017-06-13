#include <iostream>
#include <cmath>
#include "Polygone.hpp"

Polygone::Polygone(ulong color, uint _x1, uint _y1, uint _x2, uint _y2, uint _x3, uint _y3, uint _x4, uint _y4)
 : Forme(color, _x1, _y1), x1(_x1), y1(_y1), x2(_x2), y2(_y2), x3(_x3), y3(_y3), x4(_x4), y4(_y4)
{
    Forme::infotime("Construction d'un Polygone à 4 sommets"); //log
     cerr << "Construction d'un Polygone à 4 sommets" << perimetre() << endl;
     setNomForme("Polygone4"); //Nom de la forme pour le constructeur is dans Forme
}

Polygone::Polygone(ulong color, uint _x1, uint _y1, uint _x2, uint _y2, uint _x3, uint _y3, uint _x4, uint _y4, uint _x5, uint _y5)
 : Forme(color, _x1, _y1, _x2, _y2, _x3, _y3), x1(_x1), y1(_y1), x2(_x2), y2(_y2), x3(_x3), y3(_y3), x4(_x4), y4(_y4), x5(_x5), y5(_y5)
{
    Forme::infotime("Construction d'un Polygone à 5 sommets"); //log
    cerr << "Construction d'un Polygone à 5 sommets" << perimetre() << endl;
    setNomForme("Polygone5"); //Nom de la forme pour le constructeur is dans Forme
}

Polygone::Polygone(ulong color, uint _x1, uint _y1, uint _x2, uint _y2, uint _x3, uint _y3, uint _x4, uint _y4, uint _x5, uint _y5, uint _x6, uint _y6)
    : Forme(color, _x1, _y1, _x2, _y2, _x3, _y3), x1(_x1), y1(_y1), x2(_x2), y2(_y2), x3(_x3), y3(_y3), x4(_x4), y4(_y4), x5(_x5), y5(_y5), x6(_x6), y6(_y6)
{
    Forme::infotime("Construction d'un Polygone à 6 sommets"); //log
     cerr << "Construction d'un Polygone à 6 sommets" << perimetre() << endl;
     setNomForme("Polygone6"); //Nom de la forme pour le constructeur is dans Forme
}

Polygone::Polygone(ulong color, uint _x1, uint _y1, uint _x2, uint _y2, uint _x3, uint _y3, uint _x4, uint _y4, uint _x5, uint _y5, uint _x6, uint _y6, uint _x7, uint _y7)
    : Forme(color, _x1, _y1, _x2, _y2, _x3, _y3), x1(_x1), y1(_y1), x2(_x2), y2(_y2), x3(_x3), y3(_y3), x4(_x4), y4(_y4), x5(_x5), y5(_y5), x6(_x6), y6(_y6), x7(_x7), y7(_y7)
{
    Forme::infotime("Construction d'un Polygone à 7 sommets"); //log
     cerr << "Construction d'un Polygone à 7 sommets" << perimetre() << endl;
     setNomForme("Polygone7"); //Nom de la forme pour le constructeur is dans Forme
}

Polygone::Polygone(ulong color, uint _x1, uint _y1, uint _x2, uint _y2, uint _x3, uint _y3, uint _x4, uint _y4, uint _x5, uint _y5, uint _x6, uint _y6, uint _x7, uint _y7, uint _x8, uint _y8)
    : Forme(color, _x1, _y1, _x2, _y2, _x3, _y3), x1(_x1), y1(_y1), x2(_x2), y2(_y2), x3(_x3), y3(_y3), x4(_x4), y4(_y4), x5(_x5), y5(_y5), x6(_x6), y6(_y6), x7(_x7), y7(_y7), x8(_x8), y8(_y8)
{
    Forme::infotime("Construction d'un Polygone à 8 sommets"); //log
     cerr << "Construction d'un Polygone à 8 sommets" << perimetre() << endl;
     setNomForme("Polygone8"); //Nom de la forme pour le constructeur is dans Forme
}

Polygone::Polygone(ulong color, uint _x1, uint _y1, uint _x2, uint _y2, uint _x3, uint _y3, uint _x4, uint _y4, uint _x5, uint _y5, uint _x6, uint _y6, uint _x7, uint _y7, uint _x8, uint _y8, uint _x9, uint _y9)
    : Forme(color, _x1, _y1, _x2, _y2, _x3, _y3), x1(_x1), y1(_y1), x2(_x2), y2(_y2), x3(_x3), y3(_y3), x4(_x4), y4(_y4), x5(_x5), y5(_y5), x6(_x6), y6(_y6), x7(_x7), y7(_y7), x8(_x8), y8(_y8), x9(_x9), y9(_y9)
{
    Forme::infotime("Construction d'un Polygone à 9 sommets"); //log
     cerr << "Construction d'un Polygone à 9 sommets" << perimetre() << endl;
     setNomForme("Polygone9"); //Nom de la forme pour le constructeur is dans Forme
}

Polygone::Polygone(ulong color, uint _x1, uint _y1, uint _x2, uint _y2, uint _x3, uint _y3, uint _x4, uint _y4, uint _x5, uint _y5, uint _x6, uint _y6, uint _x7, uint _y7, uint _x8, uint _y8, uint _x9, uint _y9, uint _x10, uint _y10)
    : Forme(color, _x1, _y1, _x2, _y2, _x3, _y3), x1(_x1), y1(_y1), x2(_x2), y2(_y2), x3(_x3), y3(_y3), x4(_x4), y4(_y4), x5(_x5), y5(_y5), x6(_x6), y6(_y6), x7(_x7), y7(_y7), x8(_x8), y8(_y8), x9(_x9), y9(_y9), x10(_x10), y10(_y10)
{
    Forme::infotime("Construction d'un Polygone à 10 sommets"); //log
     cerr << "Construction d'un Polygone à 10 sommets" << perimetre() << endl;
     setNomForme("Polygone10"); //Nom de la forme pour le constructeur is dans Forme
}

Polygone::Polygone(istream &is)
 : Forme(is), x1(0), y1(0), x2(0), y2(0), x3(0), y3(0)
{
    Forme::infotime("Construction du Polygone à partir de l'entrée standard ('Formes.txt')"); //log

    //Assignation des valeurs aux variables x,y de chaque point
    x1 = Forme::getx1();
    x2 = Forme::getx2();
    x3 = Forme::getx3();
    y1 = Forme::gety1();
    y2 = Forme::gety2();
    y3 = Forme::gety3();

    bool fillsave = false; //variable temporaire pour l'initialisation du remplissage
    uint thicknessSave = 0;//variable temporaire pour l'initialisation l'épaiseur
    is >> fillsave >> thicknessSave; //Assignement du remplissage, ou pas, ainsi que de l'épaiseur
    setThickness(thicknessSave); //attribution de la valeur du remplissage à la forme
    setFill(fillsave); //Attribution de la valeur de l'épaiseur de la forme
}

Polygone::~Polygone()
{
    Forme::infotime("Destruction du Polygone"); //log
}

double Polygone::perimetre() const
{
    int AB = (sqrt( ((getx1()-getx2())*(getx1()-getx2())) + ((gety1()-gety2()) * (gety1()-gety2())) ) );
    int AC = (sqrt( ((getx1()-getx3())*(getx1()-getx3())) + ((gety1()-gety3()) * (gety1()-gety3())) ) );
    int BC = (sqrt( ((getx2()-getx3())*(getx2()-getx3())) + ((gety2()-gety3()) * (gety2()-gety3())) ) );

    return (AB + AC + BC);
}

void Polygone::dessiner(EZWindow &w, bool isActive) const
{
    Forme::dessiner(w);
    if (isActive) //Si Remplissage
	if (getNomForme() == "Polygone4")
	{
	    cerr << "Polygone4";
		w.drawLine(x1,y1,x2,y2);
		w.drawLine(x2,y2,x3,y3);
		w.drawLine(x3,y3,x4,y4);
		w.drawLine(x4,y4,x1,y1);
	}
	else
	{
	    cerr << " ";
	}
    else
	if (getNomForme() == "Polygone4")
	{
	    cerr << "Polygone4";
		w.drawLine(x1,y1,x2,y2);
		w.drawLine(x2,y2,x3,y3);
		w.drawLine(x3,y3,x4,y4);
		w.drawLine(x4,y4,x1,y1);
	}
	else
	{
	    cerr << " ";
	}
}

void Polygone::ecrire(ostream &os) const
{
    Forme::infotime("Sauvegarde du Polygone sur la sortie standard ('Formes.txt')"); //Log
//    os << "Polygone     " << getColor() << "       " << Forme::getAnchor().getx() << "       " << Forme::getAnchor().gety() << "       " << (Forme::getAnchor().getx() - Forme::getAnchor2().getx()) << "       " << (Forme::getAnchor2().gety() - Forme::getAnchor().gety()) << "       " << (Forme::getAnchor3().getx() - Forme::getAnchor().getx()) << "       " << (Forme::getAnchor3().gety() - Forme::getAnchor().gety());
}


